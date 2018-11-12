// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "CodeCharacter.generated.h"

UCLASS()
class PECKGAM312_API ACodeCharacter : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, Category = Camera)
		UCameraComponent* FirstPersonCameraComponent;
	
public:
	// Sets default values for this character's properties
	ACodeCharacter();
	ACodeCharacter(const FObjectInitializer& ObjectInitializer);
	float sprintSpeedMultiplier;

	void Sprint();
	void StopSprinting();
	const float BaseTurnRate = 45.0f;
	const float BaseLookUpRate = 45.0f;

protected:
	UPROPERTY(VisibleAnywhere)
	class USpringArmComponent *CameraBoom;
	class UCameraComponent* FollowCamera;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void TurnAtRate(float value);
	void LookUpRate(float value);

	template <int Index>
	void ChangeView() 
	{ 
		SetView(Index); 
	}
	void SetView(int CamNumber);
	bool isThirdPerson = true;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	//Used to change from camera to camera
	void ToggleCamera();

	// Called to bind functionality to input
	void Lateral(float value);
	void SidetoSide(float value);
	void SetupPlayerInputComponent(class UInputComponent* InputComponent);
};