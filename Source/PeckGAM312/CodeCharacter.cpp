// Fill out your copyright notice in the Description page of Project Settings.

#include "CodeCharacter.h"
#include "Components/InputComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "GameFramework/SpringArmComponent.h"
#include "EngineUtils.h"
#include "PeckCameraController.h"
#include "Camera/CameraComponent.h"

// Sets default values
ACodeCharacter::ACodeCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	sprintSpeedMultiplier = 2.0f;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraSpringArm"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.0f;
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;
}

ACodeCharacter::ACodeCharacter(const FObjectInitializer & ObjectInitializer) :Super(ObjectInitializer)
{
	FirstPersonCameraComponent = ObjectInitializer.CreateDefaultSubobject<UCameraComponent>(this, TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment()
}

// Called when the game starts or when spawned
void ACodeCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void ACodeCharacter::TurnAtRate(float value)
{

}

void ACodeCharacter::LookUpRate(float value)
{

}

void ACodeCharacter::Sprint()
{
	GetCharacterMovement()->MaxWalkSpeed *= sprintSpeedMultiplier;
}

void ACodeCharacter::StopSprinting()
{
	GetCharacterMovement()->MaxWalkSpeed /= sprintSpeedMultiplier;
}

void ACodeCharacter::SetView(int CamNumber)
{
	for (TActorIterator<APeckCameraController> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		if (CamNumber == 0) //Main (fixed) camera
		{
			ActorItr->SetFixedCamera();
			break;
		}
		else if (CamNumber == 1) //Set to Camera One
		{
			ActorItr->SetCameraOne();
			break;
		}
		else if (CamNumber == 2) //Set to Camera Two
		{
			ActorItr->SetCameraTwo();
		}
	}
}

// Called every frame
void ACodeCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACodeCharacter::ToggleCamera()
{
}

void ACodeCharacter::Lateral(float value)
{
	if (Controller && value)
	{
		//Setting up the forward(+1) and backward (-1) vector for movement
		FVector Forward = GetActorForwardVector();
		//Convert the vector into actual movement with the value
		AddMovementInput(Forward, value);
	}
}

void ACodeCharacter::SidetoSide(float value)
{
	if (Controller && value)
	{
		//Setting up the right(+1) and left(-1) vector for movement
		FVector Right = GetActorRightVector();
		//Convert the vector into actual movement with the value
		AddMovementInput(Right, value);
	}
}
void ACodeCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	check(InputComponent);

	//Sets the axis for both lateral and sidetoside
	InputComponent->BindAxis("Lateral", this, &ACodeCharacter::Lateral);
	InputComponent->BindAxis("SidetoSide", this, &ACodeCharacter::SidetoSide);
	InputComponent->BindAxis("TurnCamera", this, &ACodeCharacter::AddControllerYawInput);
	InputComponent->BindAxis("TurnAtRate", this, &ACodeCharacter::TurnAtRate);


	//Set up the action mappings to handle the sprint
	InputComponent->BindAction("Sprint", IE_Pressed, this, &ACodeCharacter::Sprint);
	InputComponent->BindAction("Sprint", IE_Released, this, &ACodeCharacter::StopSprinting);
	InputComponent->BindAction("CameraOne", IE_Pressed, this, &ACodeCharacter::ChangeView<1>);
	InputComponent->BindAction("CameraTwo", IE_Pressed, this, &ACodeCharacter::ChangeView<2>);
	InputComponent->BindAction("FixedCamera", IE_Pressed, this, &ACodeCharacter::ChangeView<3>);
}
