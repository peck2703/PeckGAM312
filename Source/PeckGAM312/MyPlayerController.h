// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class PECKGAM312_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
	TSubclassOf<class UUserWidget> wMainMenu;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
		TSubclassOf<class UUserWidget> wUIWidget;

	UFUNCTION(BlueprintPure, Category = "Stamina")
		float GetInitialStamina();
	UFUNCTION(BlueprintPure, Category = "Stamina")
		float GetCurrentStamina();
	UFUNCTION(Category = "Stamina")
		void UpdateCurrentStamina();

	UUserWidget* myMainMenu;

	UUserWidget* myUIWidget;

	virtual void BeginPlay() override;
private:
	UPROPERTY(EditAnywhere, Category = "Stamina")
		float InitialStamina;
	UPROPERTY(EditAnywhere, Category = "Stamina")
		float CurrentStamina;
};
