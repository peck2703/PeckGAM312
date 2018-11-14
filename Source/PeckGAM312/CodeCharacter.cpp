// Fill out your copyright notice in the Description page of Project Settings.

#include "CodeCharacter.h"
#include "Components/InputComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "GameFramework/SpringArmComponent.h"
#include "EngineUtils.h"
#include "PeckCameraController.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ACodeCharacter::ACodeCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	sprintSpeedMultiplier = 2.0f;
}

ACodeCharacter::ACodeCharacter(const FObjectInitializer & ObjectInitializer)
{
	//FirstPersonCameraComponent = ObjectInitializer.CreateDefaultSubobject<UCameraComponent>(this, TEXT("FirstPersonCamera")); 
	
	springArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RootComponent"));

	springArm->AttachTo(ACodeCharacter::GetRootComponent());
	springArm->TargetArmLength = 150.f;
	springArm->SetWorldRotation(FRotator(-60.0f, 0.0f, 0.0f));

	camera->AttachTo(springArm, USpringArmComponent::SocketName);
	camera->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	OurPlayerController = UGameplayStatics::GetPlayerController(this, 0);
}

// Called when the game starts or when spawned
void ACodeCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	//OurPlayerController = UGameplayStatics::GetPlayerController(this, 0);
}

void ACodeCharacter::TurnAtRate(float value)
{
	//Add movement in the X axis
	AddControllerYawInput(value * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void ACodeCharacter::LookUpRate(float value)
{
	//Add movement in the Y axis
	AddControllerPitchInput(value * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
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

	FRotator newYaw = GetActorRotation();
	newYaw.Yaw += mouseInput.X;
	SetActorRotation(newYaw);

	FRotator newPitch = springArm->GetComponentRotation();
	newPitch.Pitch = FMath::Clamp(newPitch.Pitch + mouseInput.Y, -80.0f, 0.0f);
	springArm->SetWorldRotation(newPitch);
}

void ACodeCharacter::ToggleCamera()
{
}

void ACodeCharacter::Lateral(float value)
{
	if (Controller && value)
	{
		//Creating a FRotator variable, by getting the current rotation on the controller
		const FRotator Rotation = Controller->GetControlRotation();
		//creating an FRotator based on the Yaw of the previous variable
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		//Creating a unit square (1x1) in order to get direction
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

		AddMovementInput(Direction, value);
	}
}

void ACodeCharacter::SidetoSide(float value)
{
	if (Controller && value)
	{
		//Creating a FRotator variable, by getting the current rotation on the controller
		const FRotator Rotation = Controller->GetControlRotation();
		//creating an FRotator based on the Yaw of the previous variable
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		//Creating a unit square (1x1) in order to get direction
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		AddMovementInput(Direction, value);
	}
}
void ACodeCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	check(InputComponent);

	//Sets the axis for both lateral and sidetoside
	InputComponent->BindAxis("Lateral", this, &ACodeCharacter::Lateral);
	InputComponent->BindAxis("SidetoSide", this, &ACodeCharacter::SidetoSide);
	InputComponent->BindAxis("MouseYaw", this, &ACodeCharacter::MouseYaw);
	InputComponent->BindAxis("MousePitch", this, &ACodeCharacter::MousePitch);
	InputComponent->BindAxis("TurnAtRate", this, &ACodeCharacter::TurnAtRate);


	//Set up the action mappings to handle the sprint
	InputComponent->BindAction("Sprint", IE_Pressed, this, &ACodeCharacter::Sprint);
	InputComponent->BindAction("Sprint", IE_Released, this, &ACodeCharacter::StopSprinting);
	InputComponent->BindAction("CameraOne", IE_Pressed, this, &ACodeCharacter::ChangeView<1>);
	InputComponent->BindAction("CameraTwo", IE_Pressed, this, &ACodeCharacter::ChangeView<2>);
	InputComponent->BindAction("FixedCamera", IE_Pressed, this, &ACodeCharacter::ChangeView<3>);
}

void ACodeCharacter::MouseYaw(float axis)
{
	mouseInput.X = axis;
}

void ACodeCharacter::MousePitch(float axis)
{
	mouseInput.Y = axis;
}

void ACodeCharacter::SetCameraOne(float blendTime)
{
	if (Controller)
	{
		if (Controller->GetViewTarget() != CameraOne)
		{
			SetView(1);
		}
	}
}

void ACodeCharacter::SetCameraTwo(float blendTime)
{
	if (Controller)
	{
		if (Controller->GetViewTarget() != CameraTwo)
		{
			SetView(2);
		}
	}
}

void ACodeCharacter::SetCameraFixed(float blendTime)
{
	if (Controller)
	{
		if (Controller->GetViewTarget() != FixedCamera)
		{
			SetView(0);
		}
	}
}
