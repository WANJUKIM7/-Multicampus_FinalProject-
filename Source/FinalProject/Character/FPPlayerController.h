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

private:
	void Input_Move(const FInputActionValue& InputValue);
	void Input_Turn(const FInputActionValue& InputValue);
	void Input_Jump(const FInputActionValue& InputValue);
	void Input_Interaction(const FInputActionValue& InputValue);

protected:
	/*UPROPERTY(EditAnywhere, Category = Input)
		TObjectPtr<class UInputMappingContext> IMC_Quater;

	UPROPERTY(EditAnywhere, Category = Input)
		TObjectPtr<class UInputMappingContext> IMC_QuaterJump;

	UPROPERTY(EditAnywhere, Category = Input)
		TObjectPtr<class UInputMappingContext> IMC_QuaterJumpInteraction;

	UPROPERTY(EditAnywhere, Category = Input)
		TObjectPtr<class UInputMappingContext> IMC_ThirdPerson;

	UPROPERTY(EditAnywhere, Category = Input)
		TObjectPtr<class UInputMappingContext> IMC_ThirdPersonDoubleJumpInteraction;

	UPROPERTY(EditAnywhere, Category = Input)
		TObjectPtr<class UInputMappingContext> IMC_ThirdPersonJumpInteraction;

	UPROPERTY(EditAnywhere, Category = Input)
		TObjectPtr<class UInputAction> TestAction;*/
};
