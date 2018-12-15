// Fill out your copyright notice in the Description page of Project Settings.

#include "SpawnController.h"


// Sets default values
ASpawnController::ASpawnController()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpawnRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SpawnRoot"));
	RootComponent = SpawnRoot;

	SpawnBox = CreateDefaultSubobject<UBoxComponent>(TEXT("SpawnBox"));
}

void ASpawnController::SpawnItems()
{

}

// Called when the game starts or when spawned
void ASpawnController::BeginPlay()
{
	
}

// Called every frame
void ASpawnController::Tick(float DeltaTime)
{

}

