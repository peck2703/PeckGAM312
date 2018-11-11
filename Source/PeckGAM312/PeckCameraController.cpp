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
	InputComponent->BindAxis("CameraOne", this, &APeckCameraController::SetCameraOne);
	InputComponent->BindAxis("CameraTwo", this, &APeckCameraController::SetCameraTwo);
	InputComponent->BindAxis("FixedCamera", this, &APeckCameraController::SetFixedCamera);
}

void APeckCameraController::SetCameraOne(float value)
{
	//Checks if the view target is not the camera we want to set it to and then set it
	if (OurPlayerController && OurPlayerController->GetViewTarget != CameraOne)
	{
		//Set the current target to that of the CameraOne
		OurPlayerController->SetViewTarget(CameraOne);
	}
}

void APeckCameraController::SetCameraTwo(float value)
{
	//Checks if the view target is not the camera we want to set it to and then set it
	if (OurPlayerController && OurPlayerController->GetViewTarget != CameraTwo)
	{
		//Set the current target to that of the CameraTwo
		OurPlayerController->SetViewTarget(CameraTwo);
	}
}

void APeckCameraController::SetFixedCamera(float value)
{
	//Checks if the view target is not the camera we want to set it to and then set it
	if (OurPlayerController && OurPlayerController->GetViewTarget != FixedCamera)
	{
		//Set the current target to that of the FixedCamera behind the actor
		OurPlayerController->SetViewTarget(FixedCamera);
	}
}
