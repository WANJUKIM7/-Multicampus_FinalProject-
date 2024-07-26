// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "FPGameState.generated.h"

/**
 * 
 */
UCLASS()
class FINALPROJECT_API AFPGameState : public AGameState
{
	GENERATED_BODY()

public:
	/*virtual void HandleBeginPlay() override;
	virtual void OnRep_ReplicatedHasBegunPlay() override;*/
	AFPGameState();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const;

	UPROPERTY(Transient, Replicated)
	int32 RemainingTime;

	int32 MatchPlayTime = 2000;
	int32 ShowResultWaitingTime = 5;

	UFUNCTION(BlueprintCallable)
	int32 GetAlivePlayersCount() const;

	UFUNCTION(BlueprintCallable)
	bool IsGameOver() const;

	void OnPlayerStateChanged();

private:
	TArray<class AFPPlayerState*> PlayerStates;	
};
