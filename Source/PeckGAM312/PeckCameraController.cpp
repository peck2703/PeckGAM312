// Fill out your copyright notice in the Description page of Project Settings.

#include "PeckCameraController.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"
#include "CoreMinimal.h"
#include "Components/InputComponent.h"

APeckCameraController::APeckCameraController()
{
	
}

void APeckCameraController::BeginPlay()
{
	//Grab the current player controller
	OurPlayerController = UGameplayStatics::GetPlayerController(this, 0);
	//Set the intial target view
	FixedCamera = OurPlayerController->GetViewTarget();
}

void APeckCameraController::Tick(float DeltaTime)
{
	
}

void APeckCameraController::SetupPlayerInputComponent(UInputComponent * InputComponent)
{
	check(InputComponent);
}

void APeckCameraController::SetCameraOne()
{
	if (OurPlayerController)	//if Controller is attached
	{
		
	}
}

void APeckCameraController::SetCameraTwo()
{
	if (OurPlayerController)	//if Controller is attached
	{
		
	}
}

void APeckCameraController::SetFixedCamera()
{
	if (OurPlayerController)	//if Controller is attached
	{
		
	}
}
