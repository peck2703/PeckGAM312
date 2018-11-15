// Fill out your copyright notice in the Description page of Project Settings.

#include "ComponentPawn.h"
#include "Components/SphereComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AComponentPawn::AComponentPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Create a sphere component
	USphereComponent* Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));
	//make the sphere the root component

	RootComponent = Sphere;
	//Initiate radius size
	Sphere->InitSphereRadius(50.0f);
	//Declaring type of collision?
	Sphere->SetCollisionProfileName(TEXT("Pawn"));

	//Create the mesh and then attach it to the root component that we created above
	UStaticMeshComponent* SphereMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Visual"));
	SphereMesh->AttachTo(RootComponent);

	//Appears to be finding a mesh to add to the pawn, but do we have to have the starter content availble for it to work?
	static ConstructorHelpers::FObjectFinder<UStaticMesh>SphereVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere"));
	//If the asset has been found
	if (SphereVisualAsset.Succeeded())
	{
		//Assign a value to the mesh
		SphereMesh->SetStaticMesh(SphereVisualAsset.Object);
		//set the location relative to the component it's attached to
		SphereMesh->SetRelativeLocation(FVector(0.0f, 0.0f, -40.0f));
		//set overall scale relative to world
		SphereMesh->SetWorldScale3D(FVector(0.8f));
	}

	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

// Called when the game starts or when spawned
void AComponentPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AComponentPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AComponentPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

