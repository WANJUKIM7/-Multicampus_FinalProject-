// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "FPPlayerController.generated.h"

struct FInputActionValue;

/**
 * 
 */
UCLASS()
class FINALPROJECT_API AFPPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AFPPlayerController(const FObjectInitializer& ObjectInitializer);

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

public:
	void ChangeMappingContextQuater();
	void ChangeMappingContextQuaterJump();
	void ChangeMappingContextQuaterJumpInteraction();
	void ChangeMappingContextThirdPerson();
	void ChangeMappingContextThirdPersonDoubleJumpInteraction();
	void ChangeMappingContextThirdPersonJump();

private:
	void Input_Move(const FInputActionValue& InputValue);
	void Input_Turn(const FInputActionValue& InputValue);
	void Input_Jump(const FInputActionValue& InputValue);
	void Input_Interaction(const FInputActionValue& InputValue);

protected:
	
};
