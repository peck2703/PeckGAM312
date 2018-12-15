

#include "MyPlayerController.h"
#include "Blueprint/UserWidget.h"

float AMyPlayerController::GetInitialStamina()
{
	return 0.0f;
}

float AMyPlayerController::GetCurrentStamina()
{
	return 0.0f;
}

void AMyPlayerController::UpdateCurrentStamina()
{
}

void AMyPlayerController::BeginPlay()
{
	myMainMenu = CreateWidget<UUserWidget>(this, wMainMenu);

	if (myMainMenu)
	{
		myMainMenu->AddToViewport();
	}

	bShowMouseCursor = true;
}