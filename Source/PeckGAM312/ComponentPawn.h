// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Particles/ParticleSystemComponent.h"
#include "ComponentPawn.generated.h"

UCLASS()
class PECKGAM312_API AComponentPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AComponentPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UParticleSystemComponent* OurParticleSystem;
	class UCollidingPawnMovement* OurMovementComponent;

	virtual UPawnMovementComponent* GetMovementComponent() const override;
	
	void MoveForward(float value);
	void MoveRight(float value);
	void Turn(float value);
	void ParticleToggle();
};
