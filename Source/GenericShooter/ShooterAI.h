// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "GenericShooterCharacter.h"
#include "ShooterAI.generated.h"

/**
 * 
 */
UCLASS()
class GENERICSHOOTER_API AShooterAI : public AAIController
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	APawn* PlayerPawn;

	UPROPERTY(EditDefaultsOnly)
	UBehaviorTree* BehaviorTree;
	AGenericShooterCharacter* PlayerCharacter;
	AGenericShooterCharacter* MyCharacter;
	void StartBehaviorTree(AGenericShooterCharacter* Player);
};
