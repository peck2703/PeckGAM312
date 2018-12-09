// Fill out your copyright notice in the Description page of Project Settings.

#include "PeckHUD.h"

void APeckHUD::DrawHUD()
{
	Super::DrawHUD();
	DrawLine(200, 300, 400, 500, FLinearColor::Blue);
	DrawText(textToDraw, FColor::White, HUDStartX, HUDStartY, hudFont);
}
