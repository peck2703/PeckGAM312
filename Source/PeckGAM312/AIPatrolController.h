// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Engine.h"
#include "Runtime/Engine/Classes/Engine/TargetPoint.h"
#include "Kismet/GameplayStatics.h"
#include "Components/SplineComponent.h"
#include "Components/SplineMeshComponent.h"
#include "Navigation/PathFollowingComponent.h"
#include "Runtime/CoreUObject/Public/UObject/UObjectIterator.h"
#include "AIPatrolController.generated.h"

/**
 * 
 */
UCLASS()
class PECKGAM312_API AAIPatrolController : public AAIController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;
	virtual void OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result) override;
private:
	UPROPERTY()
		TArray<AActor*> Waypoints;

	FTimerHandle TimerHandle;

	int currentWaypointIndex = 0;
	int WaypointIndexCount = 0;
	UFUNCTION()
		void GoToNextWaypoint();
};
