// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Perception/AISense.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AIPerceptionStimuliSourceComponent.h"
#include "Perception/AISense_Sight.h"
#include "Kismet/GameplayStatics.h"
#include "AI_Character_Patrol.generated.h"

UCLASS()
class PECKGAM312_API AAI_Character_Patrol : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAI_Character_Patrol();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UAIPerceptionComponent* AIPerception;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UAIPerceptionStimuliSourceComponent* AIStimuli;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UAISenseConfig_Sight* sightConfig;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		ACharacter* myCharacter;
};
