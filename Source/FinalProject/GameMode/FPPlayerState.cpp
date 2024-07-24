// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/FPPlayerState.h"
#include "FPGameState.h"

AFPPlayerState::AFPPlayerState()
{
    bIsAlive = true;
}

bool AFPPlayerState::IsAlive() const
{
    return bIsAlive;
}

void AFPPlayerState::SetAlive(bool bAlive)
{
    bIsAlive = bAlive;
	AFPGameState* FPGameState = GetWorld()->GetGameState<AFPGameState>();
	if (FPGameState)
	{
		FPGameState->OnPlayerStateChanged();
	}
}
