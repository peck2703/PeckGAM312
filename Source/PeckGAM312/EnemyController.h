// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyController.generated.h"

/**
 * 
 */
UCLASS()
class PECKGAM312_API AEnemyController : public AAIController
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Blackboard")
		class UBlackboardData* myData;
	UPROPERTY(EditAnywhere, Category = "Blackboard")
		class UBlackboardComponent* myBBComp;
	UPROPERTY(EditAnywhere, Category = "Blackboard")
		class  UBehaviorTree* myBHTree;

public:
	AEnemyController();

	virtual void Possess(APawn* InPawn) override;
	
};