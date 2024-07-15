// Fill out your copyright notice in the Description page of Project Settings.


#include "FPPlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Kismet/KismetMathLibrary.h"
#include "System/FPAssetManager.h"
#include "Data/FPInputData.h"
#include "FPGameplayTags.h"
#include "FinalProjectCharacter.h"

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
			Subsystem->AddMappingContext(InputData->InputMappingContext, 0);
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

void AFPPlayerController::Input_Move(const FInputActionValue& InputValue)
{
	FVector2D MovementVector = InputValue.Get<FVector2D>();

	if (MovementVector.X != 0)
	{
		//FVector Direction = FVector::ForwardVector * MovementVector.X;
		//GetPawn()->AddActorWorldOffset(Direction * 50.f); // * DeltaTime

		FRotator Rotator = GetControlRotation();
		FVector Direction = UKismetMathLibrary::GetForwardVector(FRotator(0, Rotator.Yaw, 0));
		GetPawn()->AddMovementInput(Direction, MovementVector.X);
	}

	if (MovementVector.Y != 0)
	{
		//FVector Direction = FVector::RightVector * MovementVector.Y;
		//GetPawn()->AddActorWorldOffset(Direction * 50.f); // * DeltaTime

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
}

void AFPPlayerController::Input_Jump(const FInputActionValue& InputValue)
{
	if (AFinalProjectCharacter* MyPlayer = Cast<AFinalProjectCharacter>(GetPawn()))
	{
		MyPlayer->Jump();
	}
}

void AFPPlayerController::Input_Interaction(const FInputActionValue& InputValue)
{
	UE_LOG(LogTemp, Log, TEXT("Interaction"));
}

