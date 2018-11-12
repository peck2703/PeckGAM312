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
		//Checks if the view target is not the camera we want to set it to and then set it
		if (OurPlayerController->GetViewTarget != CameraOne)
		{
			//Set the current target to that of the CameraOne
			OurPlayerController->SetViewTarget(CameraOne);
		}
	}
}

void APeckCameraController::SetCameraTwo()
{
	if (OurPlayerController)	//if Controller is attached
	{
		//Checks if the view target is not the camera we want to set it to and then set it
		if (OurPlayerController->GetViewTarget != CameraTwo)
		{
			//Set the current target to that of the CameraOne
			OurPlayerController->SetViewTarget(CameraTwo);
		}
	}
}

void APeckCameraController::SetFixedCamera()
{
	if (OurPlayerController)	//if Controller is attached
	{
		//Checks if the view target is not the camera we want to set it to and then set it
		if (OurPlayerController->GetViewTarget != FixedCamera)
		{
			//Set the current target to that of the CameraOne
			OurPlayerController->SetViewTarget(FixedCamera);
		}
	}
}
