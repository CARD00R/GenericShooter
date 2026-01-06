// Fill out your copyright notice in the Description page of Project Settings.


#include "gun.h"

// Sets default values
Agun::Agun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneComp = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComp"));
	SetRootComponent(SceneComp);

	SkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMesh"));
	SkeletalMesh->SetupAttachment(GetRootComponent());
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
}

