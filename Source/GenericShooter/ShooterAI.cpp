// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterAI.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
void AShooterAI::BeginPlay()
{
	Super::BeginPlay();
}

void AShooterAI::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	/*
	PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(),0);
	if (PlayerPawn)
	{
		if (LineOfSightTo(PlayerPawn))
		{
			SetFocus(PlayerPawn);
			MoveToActor(PlayerPawn,200); 
		}
		else
		{
			ClearFocus(EAIFocusPriority::Gameplay);
			StopMovement();
		}
	}*/
}

void AShooterAI::StartBehaviorTree(AGenericShooterCharacter* Player)
{
	if (BehaviorTree)
	{
		MyCharacter = Cast<AGenericShooterCharacter>(GetPawn());
		
		if (Player)
		{
			PlayerCharacter = Player;
		}
		RunBehaviorTree(BehaviorTree);
		UBlackboardComponent* MyBlackboard = GetBlackboardComponent();
		if (MyBlackboard)
		{
			MyBlackboard->SetValueAsVector("StartLocation",GetPawn()->GetActorLocation());
		}
	}
}
