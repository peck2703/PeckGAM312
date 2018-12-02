// Fill out your copyright notice in the Description page of Project Settings.

#include "AIPatrolController.h"
#include "GameFramework/Actor.h"

void AAIPatrolController::BeginPlay()
{
	Super::BeginPlay();

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATargetPoint::StaticClass(), Waypoints);

	WaypointIndexCount = Waypoints.Num();

	GoToNextWaypoint();
}
void AAIPatrolController::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult & Result)
{
	Super::OnMoveCompleted(RequestID, Result);

	GetWorldTimerManager().SetTimer(TimerHandle, this, &AAIPatrolController::GoToNextWaypoint, 3.0f, false);
}
void AAIPatrolController::GoToNextWaypoint()
{
	MoveToActor(Waypoints[currentWaypointIndex]);
	currentWaypointIndex++;
	int Cycle = currentWaypointIndex % WaypointIndexCount;
	if (currentWaypointIndex >= WaypointIndexCount - 1)
	{
		currentWaypointIndex = 0;
	}
}
