// Fill out your copyright notice in the Description page of Project Settings.

#include "Pickup_UI.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Blueprint/UserWidget.h"
#include "MyPlayerController.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
APickup_UI::APickup_UI()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Establish root component
	PickupRoot = CreateDefaultSubobject<USceneComponent>(TEXT("PickupRoot"));
	RootComponent = PickupRoot;

	//Creating the mesh for the object
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->AttachToComponent(PickupRoot, FAttachmentTransformRules::SnapToTargetNotIncludingScale);

	//This is the actual collision box that will generate overlap events
	PickupBox = CreateDefaultSubobject<UBoxComponent>(TEXT("PickupBox"));
	PickupBox->SetWorldScale3D(FVector(1.0f, 1.0f, 1.0f));

	//This was called something different in the tutorial video, but now it changed, I guess
	PickupBox->SetNotifyRigidBodyCollision(true);

	//AddDynamic was not part of Intellisense, but surprisingly it doesn't throw an error
	PickupBox->OnComponentBeginOverlap.AddDynamic(this, &APickup_UI::OnPlayerEnterPickupBox);
	PickupBox->AttachToComponent(PickupRoot, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
	
	//Attach a UI Widget to root component
	UIWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("textWidget"));
	UIWidget->AttachToComponent(PickupBox, FAttachmentTransformRules::SnapToTargetIncludingScale);
}

void APickup_UI::OnPlayerEnterPickupBox(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{	

}

// Called when the game starts or when spawned
void APickup_UI::BeginPlay()
{
	
}

// Called every frame
void APickup_UI::Tick(float DeltaTime)
{

}

