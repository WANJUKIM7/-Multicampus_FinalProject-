// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "FPPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class FINALPROJECT_API AFPPlayerState : public APlayerState
{
	GENERATED_BODY()
	
public:
	AFPPlayerState();

protected:
	UPROPERTY(BlueprintReadWrite)
	bool bIsAlive;

public:
	UFUNCTION(BlueprintCallable)
	bool IsAlive() const;

	UFUNCTION(BlueprintCallable)
	void SetAlive(bool bAlive);
};
