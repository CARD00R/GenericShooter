// Fill out your copyright notice in the Description page of Project Settings.
#include "gun.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
Agun::Agun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneComp = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComp"));
	SetRootComponent(SceneComp);

	SkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMesh"));
	SkeletalMesh->SetupAttachment(GetRootComponent());

	MuzzleFlashParticleSystem = CreateDefaultSubobject<UNiagaraComponent>(TEXT("NiagaraComp"));
	MuzzleFlashParticleSystem->SetupAttachment(SkeletalMesh);

	
}

// Called when the game starts or when spawned
void Agun::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void Agun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void Agun::PullTrigger()
{
	UE_LOG(LogTemp, Error, TEXT("BANG"));
	MuzzleFlashParticleSystem->Activate(true);
	if (MyController)
	{
		FVector ViewPointLocation;
		FRotator ViewPointRotation;
		MyController->GetPlayerViewPoint(ViewPointLocation,ViewPointRotation);
		FVector EndLocation = ViewPointLocation+(ViewPointRotation.Vector()*GunRange);

		FHitResult HitResult;
		FCollisionQueryParams Params;
		Params.AddIgnoredActor(this);
		Params.AddIgnoredActor(GetOwner());
		bool IsHit = GetWorld()->LineTraceSingleByChannel(HitResult,
			ViewPointLocation, EndLocation,
			ECC_GameTraceChannel2,Params);

		
		if (IsHit)
		{
			UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(),ImpactParticleSystem,HitResult.ImpactPoint, HitResult.ImpactPoint.Rotation());

			if (HitResult.GetActor())
			{
				UGameplayStatics::ApplyDamage(HitResult.GetActor(),BulletDamage,MyController,this,UDamageType::StaticClass());
			}
		}
	}
}

