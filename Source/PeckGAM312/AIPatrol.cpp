// Fill out your copyright notice in the Description page of Project Settings.

#include "AIPatrol.h"

const int MAXPOINTS = 50;
FVector splinePathLocations[MAXPOINTS];
int splineIndex = 1;
int totalPoints = 0;

// Sets default values
AAIPatrol::AAIPatrol()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}
// Called when the game starts or when spawned
void AAIPatrol::BeginPlay()
{
	Super::BeginPlay();
	
}
// Called every frame
void AAIPatrol::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
// Called to bind functionality to input
void AAIPatrol::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AAIPatrol::GetPoints()
{
}

