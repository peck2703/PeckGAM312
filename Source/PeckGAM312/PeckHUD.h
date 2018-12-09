// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "PeckHUD.generated.h"

/**
 * 
 */
UCLASS()
class PECKGAM312_API APeckHUD : public AHUD
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HUDFont)
	UFont* hudFont;

	UPROPERTY(EditAnywhere)
		float HUDStartX = 0.0f;
	UPROPERTY(EditAnywhere)
		float HUDStartY = 0.0f;
	UPROPERTY(EditAnywhere)
		FString textToDraw = "";

	virtual void DrawHUD() override;
};
