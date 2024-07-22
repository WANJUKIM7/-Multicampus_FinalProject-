// Fill out your copyright notice in the Description page of Project Settings.


#include "FPPlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Kismet/KismetMathLibrary.h"
#include "System/FPAssetManager.h"
#include "Data/FPInputData.h"
#include "FPGameplayTags.h"
#include "FPCharacter.h"
#include "FPPlayer.h"

AFPPlayerController::AFPPlayerController(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void AFPPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	if (const UFPInputData* InputData = UFPAssetManager::GetAssetByName<UFPInputData>("InputData"))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(InputData->IMC_Quater, 0);
		}
	}
}

void AFPPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (const UFPInputData* InputData = UFPAssetManager::GetAssetByName<UFPInputData>("InputData"))
	{
		UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

		auto Action1 = InputData->FindInputActionByTag(FPGameplayTags::Input_Action_Move);
		EnhancedInputComponent->BindAction(Action1, ETriggerEvent::Triggered, this, &ThisClass::Input_Move);

		auto Action2 = InputData->FindInputActionByTag(FPGameplayTags::Input_Action_Turn);
		EnhancedInputComponent->BindAction(Action2, ETriggerEvent::Triggered, this, &ThisClass::Input_Turn);

		auto Action3 = InputData->FindInputActionByTag(FPGameplayTags::Input_Action_Jump);
		EnhancedInputComponent->BindAction(Action3, ETriggerEvent::Triggered, this, &ThisClass::Input_Jump);

		auto Action4 = InputData->FindInputActionByTag(FPGameplayTags::Input_Action_Interaction);
		EnhancedInputComponent->BindAction(Action4, ETriggerEvent::Triggered, this, &ThisClass::Input_Interaction);
	}
}

void AFPPlayerController::ChangeMappingContextQuater()
{
	if (const UFPInputData* InputData = UFPAssetManager::GetAssetByName<UFPInputData>("InputData"))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
		{
			Subsystem->ClearAllMappings();

			Subsystem->AddMappingContext(InputData->IMC_Quater, 0);
			UE_LOG(LogTemp, Log, TEXT("AFPPlayerController::ChangeMappingContextQuater()"));
		}
	}
}

void AFPPlayerController::ChangeMappingContextQuaterJump()
{
	if (const UFPInputData* InputData = UFPAssetManager::GetAssetByName<UFPInputData>("InputData"))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
		{
			Subsystem->ClearAllMappings();

			Subsystem->AddMappingContext(InputData->IMC_QuaterJump, 0);
		}
	}
}

void AFPPlayerController::ChangeMappingContextQuaterJumpInteraction()
{
	if (const UFPInputData* InputData = UFPAssetManager::GetAssetByName<UFPInputData>("InputData"))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
		{
			Subsystem->ClearAllMappings();

			Subsystem->AddMappingContext(InputData->IMC_QuaterJumpInteraction, 0);
		}
	}
}

void AFPPlayerController::ChangeMappingContextThirdPerson()
{
	if (const UFPInputData* InputData = UFPAssetManager::GetAssetByName<UFPInputData>("InputData"))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
		{
			Subsystem->ClearAllMappings();

			Subsystem->AddMappingContext(InputData->IMC_ThirdPerson, 0);
		}
	}
}

void AFPPlayerController::ChangeMappingContextThirdPersonDoubleJumpInteraction()
{
	if (const UFPInputData* InputData = UFPAssetManager::GetAssetByName<UFPInputData>("InputData"))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
		{
			Subsystem->ClearAllMappings();

			Subsystem->AddMappingContext(InputData->IMC_ThirdPersonDoubleJumpInteraction, 0);
		}
	}
}

void AFPPlayerController::ChangeMappingContextThirdPersonJump()
{
	if (const UFPInputData* InputData = UFPAssetManager::GetAssetByName<UFPInputData>("InputData"))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
		{
			Subsystem->ClearAllMappings();

			Subsystem->AddMappingContext(InputData->IMC_ThirdPersonJumpInteraction, 0);
		}
	}
}

void AFPPlayerController::Input_Move(const FInputActionValue& InputValue)
{
	FVector2D MovementVector = InputValue.Get<FVector2D>();
	if (MovementVector.X != 0)
	{
		FRotator Rotator = GetControlRotation();
		FVector Direction = UKismetMathLibrary::GetForwardVector(FRotator(0, Rotator.Yaw, 0));
		GetPawn()->AddMovementInput(Direction, MovementVector.X);
	}

	if (MovementVector.Y != 0)
	{
		FRotator Rotator = GetControlRotation();
		FVector Direction = UKismetMathLibrary::GetRightVector(FRotator(0, Rotator.Yaw, 0));
		GetPawn()->AddMovementInput(Direction, MovementVector.Y);
	}

}

void AFPPlayerController::Input_Turn(const FInputActionValue& InputValue)
{
	float ValX = InputValue.Get<FVector2D>().X;
	float ValY = InputValue.Get<FVector2D>().Y;
	AddYawInput(ValX);
	AddPitchInput(ValY);
	//UE_LOG(LogTemp, Log, TEXT("Input_Turn"));
}

void AFPPlayerController::Input_Jump(const FInputActionValue& InputValue)
{
	if (AFPCharacter* MyPlayer = Cast<AFPCharacter>(GetPawn()))
	{
		MyPlayer->Jump();
	}
}

void AFPPlayerController::Input_Interaction(const FInputActionValue& InputValue)
{
	/*if (AFPPlayer* MyPlayer = Cast<AFPPlayer>(GetPawn()))
	{
		if (MyPlayer->GetIsInteracting() == false)
			MyPlayer->SetIsInteracting(true);
	}*/
	UE_LOG(LogTemp, Log, TEXT("Interaction"));
}

