// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/FPGameState.h"
#include "FPPlayerState.h"

int32 AFPGameState::GetAlivePlayersCount() const
{
	int32 AliveCount = 0;
	for (const auto& PlayerState : PlayerArray)
	{
		AFPPlayerState* FPPlayerState = Cast<AFPPlayerState>(PlayerState);
		if (FPPlayerState && FPPlayerState->IsAlive())
		{
			AliveCount++;
		}
	}
	return AliveCount;
}

bool AFPGameState::IsGameOver() const
{
	return GetAlivePlayersCount() <= 1;
}

void AFPGameState::OnPlayerStateChanged()
{
	if (IsGameOver())
	{
		// Handle game over logic here
		UE_LOG(LogTemp, Log, TEXT("Game Over!"));
	}
}
