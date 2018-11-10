// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CodeCharacter.generated.h"
#include "GameFramework\CharacterMovementComponent.h"

UCLASS()
class PECKGAM312_API ACodeCharacter : public ACharacter
{

public:
	// Sets default values for this character's properties
	ACodeCharacter();

	float sprintSpeedMultiplier;

	void Sprint();
	void StopSprinting();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)override;
	void Lateral(float value);
	void SidetoSide(float value);
	void SetupPlayerInputComponent(class UInputComponent* InputComponent);

	
	
};
