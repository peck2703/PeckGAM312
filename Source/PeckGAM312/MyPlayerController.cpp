

#include "MyPlayerController.h"
#include "Blueprint/UserWidget.h"

void AMyPlayerController::BeginPlay()
{
	myMainMenu = CreateWidget<UUserWidget>(this, wMainMenu);

	if (myMainMenu)
	{
		myMainMenu->AddToViewport();
	}

	bShowMouseCursor = true;
}
