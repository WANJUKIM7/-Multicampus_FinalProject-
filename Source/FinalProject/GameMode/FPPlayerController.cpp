// Fill out your copyright notice in the Description page of Project Settings.


#include "FPPlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Kismet/KismetMathLibrary.h"

AFPPlayerController::AFPPlayerController(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void AFPPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (Subsystem)
	{
		Subsystem->AddMappingContext(IMC_ThirdPerson, 0);
	}
}

void AFPPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (auto* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInputComponent->BindAction(TestAction, ETriggerEvent::Triggered, this, &ThisClass::Input_Test);

	}

}

void AFPPlayerController::Input_Test(const FInputActionValue& InputValue)
{
	GEngine->AddOnScreenDebugMessage(0, 1.0f, FColor::Cyan, TEXT("Test"));
}

