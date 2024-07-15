// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameplayTagContainer.h"
#include "Engine/DataAsset.h"
#include "FPInputData.generated.h"

class UInputAction;
class UInputMappingContext;

USTRUCT()
struct FPInputAction
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FGameplayTag InputTag = FGameplayTag::EmptyTag;

	UPROPERTY()
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
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UInputMappingContext> InputMappingContext;
	
	UPROPERTY(EditDefaultsOnly)
	TArray<FPInputAction>InputActions;
	//TArray<TObjectPtr<UInputAction>> InputActions;
};
