// Copyright Epic Games, Inc. All Rights Reserved.

#include "GameMode/FPGameMode.h"
#include "Character/FPPlayer.h"
#include "UObject/ConstructorHelpers.h"
#include "Character/FPPlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "FPGameState.h"

AFPGameMode::AFPGameMode()
{
	// set default pawn class to our Blueprinted character
	/*static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Script/FinalProject.FPPlayer"));*/
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Script/Engine.Blueprint'/Game/Programming/Blueprints/BP_Player.BP_Player_C'"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	PlayerControllerClass = AFPPlayerController::StaticClass();
	PlayerStateClass = AFPPlayerState::StaticClass();
	GameStateClass = AFPGameState::StaticClass();
}

AFPPlayer* AFPGameMode::GetSpawnedPlayer() const
{
	return SpawnedPlayer;
	//return Players[0];
}

TArray<AFPPlayer*> AFPGameMode::GetAllPlayers() const
{
	return Players;
}

void AFPGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);
	UE_LOG(LogTemp, Log, TEXT("AFPGameMode::PostLogin"));
	AFPPlayerState* NewPlayerState = NewPlayer->GetPlayerState<AFPPlayerState>();
	if (NewPlayerState)
	{
		NewPlayerState->SetAlive(true);
	}

	AFPPlayer* NewPlayerPawn = Cast<AFPPlayer>(NewPlayer->GetPawn());
	if (NewPlayerPawn)
	{
		Players.Add(NewPlayerPawn);
	}

	AFPGameState* FPGameState = GetGameState<AFPGameState>();
	if (FPGameState)
	{
		FPGameState->OnPlayerStateChanged();
	}
}

void AFPGameMode::Logout(AController* Exiting)
{
	Super::Logout(Exiting);

	UE_LOG(LogTemp, Log, TEXT("AFPGameMode::Logout"));

	AFPPlayer* ExitingPlayerPawn = Cast<AFPPlayer>(Exiting->GetPawn());
	if (ExitingPlayerPawn)
	{
		Players.Remove(ExitingPlayerPawn);
	}

	if (AFPGameState* FPGameState = GetGameState<AFPGameState>())
	{
		FPGameState->OnPlayerStateChanged();
	}
}

void AFPGameMode::BeginPlay()
{
	Super::BeginPlay();

	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, 0);
	if (PlayerController)
	{
		SpawnedPlayer = Cast<AFPPlayer>(PlayerController->GetPawn());
	}

	GameState = GetGameState<AFPGameState>();

	/*for (int32 PlayerIndex = 0; PlayerIndex < UGameplayStatics::GetNumPlayers(this); ++PlayerIndex)
	{
		APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, PlayerIndex);
		if (PlayerController)
		{
			AFPPlayer* Player = Cast<AFPPlayer>(PlayerController->GetPawn());
			if (Player)
			{
				Players.Add(Player);
			}
		}
	}*/
}

void AFPGameMode::HandlePlayerDeath()
{
	/*if (GameState)
	{
		GameState->OnPlayerStateChanged();
	}*/
}
