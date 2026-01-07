// Copyright Epic Games, Inc. All Rights Reserved.

#include "GenericShooterGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "GenericShooterCharacter.h"
#include "ShooterAI.h"
AGenericShooterGameMode::AGenericShooterGameMode()
{
	// stub
}

void AGenericShooterGameMode::BeginPlay()
{
	Super::BeginPlay();
	AGenericShooterCharacter* Player =
		Cast<AGenericShooterCharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(),0));

	TArray<AActor*> ShooterAIActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(),AShooterAI::StaticClass(),ShooterAIActors);

	for (AActor* actor: ShooterAIActors)
	{
		AShooterAI* ShooterAI = Cast<AShooterAI>(actor);
		ShooterAI->StartBehaviorTree(Player);
	}
}
