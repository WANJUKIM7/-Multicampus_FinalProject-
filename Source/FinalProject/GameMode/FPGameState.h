// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "FPGameState.generated.h"

/**
 * 
 */
UCLASS()
class FINALPROJECT_API AFPGameState : public AGameStateBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	int32 GetAlivePlayersCount() const;

	UFUNCTION(BlueprintCallable)
	bool IsGameOver() const;

	void OnPlayerStateChanged();

private:
	TArray<class AFPPlayerState*> PlayerStates;	
};
