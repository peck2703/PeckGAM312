// Fill out your copyright notice in the Description page of Project Settings.

#include "AI_Character_Patrol.h"


// Sets default values
AAI_Character_Patrol::AAI_Character_Patrol()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	myCharacter = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);

	//AIPerception = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AIPerception"));
	//AIPerception->ConfigureSense(*sightConfig);

	//AIStimuli = CreateDefaultSubobject<UAIPerceptionStimuliSourceComponent>(TEXT("AIStimuli"));

	/*sightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("Sight Config"));
	sightConfig->SightRadius = 300.f;
	sightConfig->LoseSightRadius = 400.f;
	sightConfig->PeripheralVisionAngleDegrees = 180.f;*/

	
}

// Called when the game starts or when spawned
void AAI_Character_Patrol::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAI_Character_Patrol::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}