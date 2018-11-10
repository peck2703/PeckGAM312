// Fill out your copyright notice in the Description page of Project Settings.

#include "CodeCharacter.h"
#include "Components/InputComponent.h"



// Sets default values
ACodeCharacter::ACodeCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	sprintSpeedMultiplier = 2.0f;
}

// Called when the game starts or when spawned
void ACodeCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACodeCharacter::Sprint()
{
	GetCharacterMovement()->MaxWalkSpeed *= sprintSpeedMultiplier;
}

void ACodeCharacter::StopSprinting()
{
	GetCharacterMovement()->MaxWalkSpeed /= sprintSpeedMultiplier;
}

// Called every frame
void ACodeCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACodeCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ACodeCharacter::Lateral(float value)
{
	if (Controller && value)
	{
		//Setting up the forward(+1) and backward (-1) vector for movement
		FVector Forward = GetActorForwardVector();
		//Convert the vector into actual movement with the value
		AddMovementInput(Forward, value);
	}
}

void ACodeCharacter::SidetoSide(float value)
{
	if (Controller && value)
	{
		//Setting up the right(+1) and left(-1) vector for movement
		FVector Right = GetActorRightVector();
		//Convert the vector into actual movement with the value
		AddMovementInput(Right, value);
	}
}
void ACodeCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	check(InputComponent);

	//Sets the axis for both lateral and sidetoside
	InputComponent->BindAxis("Lateral", this, &ACodeCharacter::Lateral);
	InputComponent->BindAxis("SidetoSide", this, &ACodeCharacter::SidetoSide);

	//Set up the action mappings to handle the sprint
	InputComponent->BindAction("Sprint", IE_Pressed, this, &ACodeCharacter::Sprint);
	InputComponent->BindAction("Sprint", IE_Released, this, &ACodeCharacter::StopSprinting);
}
