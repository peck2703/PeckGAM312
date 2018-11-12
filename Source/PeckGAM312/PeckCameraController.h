// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PeckCameraController.generated.h"


UCLASS()
class PECKGAM312_API APeckCameraController : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = Cameras)
	AActor* CameraOne;

	UPROPERTY(EditAnywhere, Category = Cameras)
	AActor* CameraTwo;

	UPROPERTY(EditAnywhere, Category = Cameras)
	AActor* FixedCamera;

public:
	APeckCameraController();
protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	void SetupPlayerInputComponent(class UInputComponent* InputComponent);
	APlayerController* OurPlayerController;

	void SetCameraOne();
	void SetCameraTwo();
	void SetFixedCamera();

};
