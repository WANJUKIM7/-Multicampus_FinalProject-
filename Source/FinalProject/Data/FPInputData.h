// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameplayTagContainer.h"
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FPInputData.generated.h"

class UInputAction;
class UInputMappingContext;

USTRUCT()
struct FPInputAction
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
	FGameplayTag InputTag = FGameplayTag::EmptyTag;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UInputAction> InputAction = nullptr;
};

/**
 * 
 */
UCLASS()
class FINALPROJECT_API UFPInputData : public UDataAsset
{
	GENERATED_BODY()
	
public:
	const UInputAction* FindInputActionByTag(const FGameplayTag& InputTag) const;

public:
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UInputMappingContext> IMC_Quater;
	
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UInputMappingContext> IMC_QuaterJump;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UInputMappingContext> IMC_QuaterJumpInteraction;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UInputMappingContext> IMC_ThirdPerson;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UInputMappingContext> IMC_ThirdPersonJumpInteraction;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UInputMappingContext> IMC_ThirdPersonDoubleJumpInteraction;

	UPROPERTY(EditDefaultsOnly)
	TArray<FPInputAction> InputActions;
};
