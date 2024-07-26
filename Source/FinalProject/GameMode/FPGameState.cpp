// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/FPGameState.h"
#include "FPPlayerState.h"
#include "FPLogChannels.h"
#include "Net/UnrealNetwork.h"

//void AFPGameState::HandleBeginPlay()
//{
//	FP_LOG(LogFP, Log, TEXT("%s"), TEXT("Begin"));
//
//	Super::HandleBeginPlay();
//
//	FP_LOG(LogFP, Log, TEXT("%s"), TEXT("End"));
//}
//
//void AFPGameState::OnRep_ReplicatedHasBegunPlay()
//{
//	FP_LOG(LogFP, Log, TEXT("%s"), TEXT("Begin"));
//
//	Super::OnRep_ReplicatedHasBegunPlay();
//
//	FP_LOG(LogFP, Log, TEXT("%s"), TEXT("End"));
//}

AFPGameState::AFPGameState()
{
	RemainingTime = MatchPlayTime;
}

void AFPGameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AFPGameState, RemainingTime);
}

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
	FP_LOG(LogFP, Log, TEXT("%s"), TEXT("Begin"));
	if (IsGameOver())
	{
		// Handle game over logic here
	}
}
