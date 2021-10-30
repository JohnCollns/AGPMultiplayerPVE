// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "Components/InputComponent.h"
#include "FirstPersonAnimInstance.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Net/UnrealNetwork.h"
#include "HealthComponent.h"
#include "MultiplayerGameMode.h"
#include "Engine/World.h"
#include "PlayerHUD.h"
#include "GameFramework/HUD.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//AutoPossessPlayer = EAutoReceiveInput::Player0;

	//Set default member variable values
	LookSensitivity = 1.0f;
	SprintMultiplier = 1.5f;

	SprintMovementSpeed = GetCharacterMovement()->MaxWalkSpeed * SprintMultiplier;
	NormalMovementSpeed = GetCharacterMovement()->MaxWalkSpeed;
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	//Initialise the camera variable
	Camera = FindComponentByClass<UCameraComponent>();
	//Initialise the health component
	HealthComponent = FindComponentByClass<UHealthComponent>();
	//UE_LOG(LogTemp, Warning, TEXT("IM HERE"))
	if (HealthComponent)
		HealthComponent->SetIsReplicated(true);

	// Get the skeletal mesh and then get the anim instance from it cast to the first person anim instance.
	USkeletalMeshComponent* SkeletalMesh = Cast<USkeletalMeshComponent>(GetDefaultSubobjectByName(TEXT("Arms")));
	if (SkeletalMesh) // Make sure the skeletal mesh was found
	{
		AnimInstance = Cast<UFirstPersonAnimInstance>(SkeletalMesh->GetAnimInstance());
	}
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &APlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("Strafe"), this, &APlayerCharacter::Strafe);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &APlayerCharacter::LookUp);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &APlayerCharacter::Turn);

	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction(TEXT("Sprint"), EInputEvent::IE_Pressed, this, &APlayerCharacter::SprintStart);
	PlayerInputComponent->BindAction(TEXT("Sprint"), EInputEvent::IE_Released, this, &APlayerCharacter::SprintEnd);
	PlayerInputComponent->BindAction(TEXT("Reload"), EInputEvent::IE_Pressed, this, &APlayerCharacter::Reload);
}

void APlayerCharacter::MoveForward(float Value) 
{
	/*
		What is frame rate independence?

		This is when object movement is not tied to the frame rate. Regardless of how quickly
		each frame is calculated, objects will move the same amount over the same period
		of time. If something was frame rate dependent, the speed of movement of objects
		in the world would be tied to the framerate, so players with a higher frame rate
		would be able to move quicker than those players with weaker machines that are
		running on a lower framerate.

		Why don't we use DeltaSeconds for movement?
		
		The CharacterMovementComponent attached to the ACharacter class automatically
		deals with frame rate independence of movement. This is only the case for the 
		ACharacter class and is not the case for movement applied to APawn class derived
		actors.
	*/
	FRotator ForwardRotation = GetControlRotation();
	ForwardRotation.Roll = 0.0f;
	ForwardRotation.Pitch = 0.0f;
	AddMovementInput(ForwardRotation.Vector(), Value);
}

void APlayerCharacter::Strafe(float Value) 
{
	AddMovementInput(GetActorRightVector(), Value);
}

void APlayerCharacter::LookUp(float Value) 
{
	/*
		Why don't we use DeltaSeconds for mouse input?

		The Value of a mouse input axis is sampled every frame by calculating the distance
		that the mouse has moved over that frame in the X and Y axes. So moving the mouse a
		certain distance over a certain period of time is the same regardless of the frame rate.
		If the frame rate is higher, the incremental distances of the mouse movement per frame
		(i.e. the Value passed into this function) will be smaller than if the frame rate was slower.
		If the frame rate is slower then those incremental distances per frame would be larger.
	*/
	FRotator LookUpRotation = FRotator::ZeroRotator;
	LookUpRotation.Pitch = Value * LookSensitivity;
	if (Camera)
	{
		if (Camera->RelativeRotation.Pitch + LookUpRotation.Pitch < 90.0f
			&& Camera->RelativeRotation.Pitch + LookUpRotation.Pitch > -90.0f)
		{
			Camera->AddRelativeRotation(LookUpRotation);
			Camera->RelativeRotation.Yaw = 0.0f;
			Camera->RelativeRotation.Roll = 0.0f;
		}
	}
}

void APlayerCharacter::Turn(float Value) 
{
	AddControllerYawInput(Value * LookSensitivity);
}

void APlayerCharacter::SprintStart()
{
	ServerSprintStart();
	GetCharacterMovement()->MaxWalkSpeed = SprintMovementSpeed;

	if (AnimInstance)
	{
		AnimInstance->bIsSprinting = true;
	}
}

void APlayerCharacter::SprintEnd()
{
	ServerSprintEnd();
	GetCharacterMovement()->MaxWalkSpeed = NormalMovementSpeed;

	if (AnimInstance)
	{
		AnimInstance->bIsSprinting = false;
	}
}

void APlayerCharacter::ServerSprintStart_Implementation()
{
	GetCharacterMovement()->MaxWalkSpeed = SprintMovementSpeed;
}

void APlayerCharacter::ServerSprintEnd_Implementation()
{
	GetCharacterMovement()->MaxWalkSpeed = NormalMovementSpeed;
}

void APlayerCharacter::Reload()
{
	BlueprintReload();
}

void APlayerCharacter::OnDeath()
{
	if (GetLocalRole() == ROLE_Authority)
	{
		AMultiplayerGameMode* MultiplayerGameMode = Cast<AMultiplayerGameMode>(GetWorld()->GetAuthGameMode());
		if (MultiplayerGameMode)
		{
			MultiplayerGameMode->Respawn(GetController());
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Unable to find the GameMode"))
		}
	}
}


void APlayerCharacter::SetPlayerHUDVisibility_Implementation(bool bHUDVisible)
{
	if (GetLocalRole() == ROLE_AutonomousProxy)
	{
		if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
		{
			APlayerHUD* PlayerHUD = Cast<APlayerHUD>(PlayerController->GetHUD());
			if (PlayerHUD)
			{
				bHUDVisible ? PlayerHUD->ShowHUD() : PlayerHUD->HideHUD();
				UE_LOG(LogTemp, Warning, TEXT("Hiding the HUD"))
			}
			else
			{
				UE_LOG(LogTemp, Error, TEXT("Can't find HUD on controller. AUTONOMOUS"))
			}
		}
	}
}


