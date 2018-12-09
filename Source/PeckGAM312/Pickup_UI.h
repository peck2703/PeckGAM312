// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/ShapeComponent.h"
#include "Components/WidgetComponent.h"
#include "Pickup_UI.generated.h"

UCLASS()
class PECKGAM312_API APickup_UI : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickup_UI();

	//Set up a Drop-down menu for user to select a widget for the interaction type
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
		TSubclassOf<class UUserWidget> myWidgetUI;

	//pointer to store the widget
	UUserWidget* myUIWidget;

	//Handles the actual interaction event
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* Mesh;
	UPROPERTY(EditAnywhere)
		USceneComponent* PickupRoot;
	UPROPERTY(EditAnywhere)
		UShapeComponent* PickupBox;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UWidgetComponent* UIWidget;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString textToDisplay = "";
	UFUNCTION()
		void OnPlayerEnterPickupBox(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
