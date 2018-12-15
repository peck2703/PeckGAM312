// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Peck312GameMode.generated.h"

/**
 * 
 */
UCLASS()
class PECKGAM312_API APeck312GameMode : public AGameModeBase
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
		void AddScore();
	
	
	
};
