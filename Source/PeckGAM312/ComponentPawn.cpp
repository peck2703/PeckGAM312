// Fill out your copyright notice in the Description page of Project Settings.

#include "ComponentPawn.h"
#include "Components/InputComponent.h"
#include "Components/SphereComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "CollidingPawnMovement.h"

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

	// Create a particle system that we can activate or deactivate
	OurParticleSystem = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("MovementParticles"));
	OurParticleSystem->SetupAttachment(SphereMesh);
	OurParticleSystem->bAutoActivate = false;
	OurParticleSystem->SetRelativeLocation(FVector(-20.0f, 0.0f, 20.0f));
	static ConstructorHelpers::FObjectFinder<UParticleSystem> ParticleAsset(TEXT("/Game/StarterContent/Particles/P_Fire.P_Fire"));
	if (ParticleAsset.Succeeded())
	{
		OurParticleSystem->SetTemplate(ParticleAsset.Object);
	}

	// Use a spring arm to give the camera smooth, natural-feeling motion.
	USpringArmComponent* SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraAttachmentArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->RelativeRotation = FRotator(-45.f, 0.f, 0.f);
	SpringArm->TargetArmLength = 400.0f;
	SpringArm->bEnableCameraLag = true;
	SpringArm->CameraLagSpeed = 3.0f;

	// Create a camera and attach to our spring arm
	UCameraComponent* Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("ActualCamera"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);

	AutoPossessPlayer = EAutoReceiveInput::Player0;

	// Create an instance of our movement component, and tell it to update our root component.
	OurMovementComponent = CreateDefaultSubobject<UCollidingPawnMovement>(TEXT("CustomMovementComponent"));
	OurMovementComponent->UpdatedComponent = RootComponent;
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
	PlayerInputComponent->BindAction("ParticleToggle", IE_Pressed, this, &AComponentPawn::ParticleToggle);

	PlayerInputComponent->BindAxis("MoveForward", this, &AComponentPawn::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AComponentPawn::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &AComponentPawn::Turn);
}

UPawnMovementComponent * AComponentPawn::GetMovementComponent() const
{
	return OurMovementComponent;
}

void AComponentPawn::MoveForward(float AxisValue)
{
	if (OurMovementComponent && (OurMovementComponent->UpdatedComponent == RootComponent))
	{
		OurMovementComponent->AddInputVector(GetActorForwardVector() * AxisValue);
	}
}

void AComponentPawn::MoveRight(float AxisValue)
{
	if (OurMovementComponent && (OurMovementComponent->UpdatedComponent == RootComponent))
	{
		OurMovementComponent->AddInputVector(GetActorRightVector() * AxisValue);
	}
}

void AComponentPawn::Turn(float AxisValue)
{
	FRotator NewRotation = GetActorRotation();
	NewRotation.Yaw += AxisValue;
	SetActorRotation(NewRotation);
}

void AComponentPawn::ParticleToggle()
{
	if (OurParticleSystem && OurParticleSystem->Template)
	{
		OurParticleSystem->ToggleActive();
	}
}

