// Copyright Epic Games, Inc. All Rights Reserved.

#include "GameMode/FPGameMode.h"
#include "Character/FPPlayer.h"
#include "UObject/ConstructorHelpers.h"
#include "Character/FPPlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "FPGameState.h"
#include "FPLogChannels.h"
#include "GameFramework/PlayerStart.h"
#include "EngineUtils.h"
#include "Levels/FPLevelBase.h"

AFPGameMode::AFPGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Script/Engine.Blueprint'/Game/Programming/Blueprints/BP_Player.BP_Player_C'"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	PlayerControllerClass = AFPPlayerController::StaticClass();
	PlayerStateClass = AFPPlayerState::StaticClass();
	GameStateClass = AFPGameState::StaticClass();
}

FTransform AFPGameMode::GetRandomStartTransform() const
{
	if (PlayerStartArray.Num() == 0)
	{
		return FTransform(FVector(0.0f, 0.0f, 230.0f));
	}

	int32 RandIndex = FMath::RandRange(0, PlayerStartArray.Num() - 1);
	return PlayerStartArray[RandIndex]->GetActorTransform();
}

void AFPGameMode::OnPlayerDead()
{
	FP_LOG(LogFP, Log, TEXT("%s"), TEXT("Begin"));
	AFPGameState* FPGameState = GetGameState<AFPGameState>();
	if (FPGameState && FPGameState->GetAlivePlayersCount() <= 1)
	{
		FP_LOG(LogFP, Log, TEXT("%s"), TEXT("Winner!"));
		FinishMatch();
	}
}

//void AFPGameMode::PreLogin(const FString& Options, const FString& Address, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage)
//{
//	FP_LOG(LogFP, Log, TEXT("%s"), TEXT("========================================"));
//	FP_LOG(LogFP, Log, TEXT("%s"), TEXT("Begin"));
//
//	Super::PreLogin(Options, Address, UniqueId, ErrorMessage);
//
//	FP_LOG(LogFP, Log, TEXT("%s"), TEXT("End"));
//}
//
//APlayerController* AFPGameMode::Login(UPlayer* NewPlayer, ENetRole InRemoteRole, const FString& Portal, const FString& Options, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage)
//{
//	FP_LOG(LogFP, Log, TEXT("%s"), TEXT("Begin"));
//
//	APlayerController* NewPlayerController = Super::Login(NewPlayer, InRemoteRole, Portal, Options, UniqueId, ErrorMessage);
//
//	FP_LOG(LogFP, Log, TEXT("%s"), TEXT("End"));
//
//	return NewPlayerController;
//}
//
//void AFPGameMode::PostLogin(APlayerController* NewPlayer)
//{
//	FP_LOG(LogFP, Log, TEXT("%s"), TEXT("Begin"));
//
//	Super::PostLogin(NewPlayer);
//
//	UNetDriver* NetDriver = GetNetDriver();
//	if (NetDriver)
//	{
//		for (const auto& Connection : NetDriver->ClientConnections)
//		{
//			FP_LOG(LogFP, Log, TEXT("Client Connections : %s"), *Connection->GetName());
//		}
//	}
//	else
//	{
//		FP_LOG(LogFP, Log, TEXT("%s"), TEXT("No NetDriver"));
//	}
//
//	FP_LOG(LogFP, Log, TEXT("%s"), TEXT("End"));
//}

void AFPGameMode::StartPlay()
{
	//FP_LOG(LogFP, Log, TEXT("%s"), TEXT("Begin"));
	Super::StartPlay();
	/*UNetDriver* NetDriver = GetNetDriver();
	if (NetDriver)
	{
		for (const auto& Connection : NetDriver->ClientConnections)
		{
			FP_LOG(LogFP, Log, TEXT("Client Connections : %s"), *Connection->GetName());
		}
	}
	else
	{
		FP_LOG(LogFP, Log, TEXT("%s"), TEXT("No NetDriver"));
	}
	FP_LOG(LogFP, Log, TEXT("%s"), TEXT("End"));*/
	InitializeLevelSettings();
	for (APlayerStart* PlayerStart : TActorRange<APlayerStart>(GetWorld()))
	{
		PlayerStartArray.Add(PlayerStart);
	}
}

void AFPGameMode::InitializeLevelSettings()
{
    UWorld* World = GetWorld();
    if (!World) return;

    TArray<AActor*> LevelActors;
    UGameplayStatics::GetAllActorsOfClass(World, AFPLevelBase::StaticClass(), LevelActors);

    if (LevelActors.Num() > 0)
    {
        AFPLevelBase* LevelActor = Cast<AFPLevelBase>(LevelActors[0]);
        if (LevelActor)
        {
            LevelActor->InitializeLevelSettings();
        }
    }
}

//void AFPGameMode::GetSpawnedPlayer()
//{
//	return SpawnedPlayer;
//}

void AFPGameMode::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	GetWorldTimerManager().SetTimer(GameTimerHandle, this, &AFPGameMode::DefaultGameTimer, GetWorldSettings()->GetEffectiveTimeDilation(), true);
}

void AFPGameMode::DefaultGameTimer()
{
	AFPGameState* const FPGameState = Cast<AFPGameState>(GameState);

	if (FPGameState && FPGameState->RemainingTime > 0)
	{
		FPGameState->RemainingTime--;
		//FP_LOG(LogFP, Log, TEXT("Remaining Time : %d"), FPGameState->RemainingTime);
		if (FPGameState->RemainingTime <= 0)
		{
			if (GetMatchState() == MatchState::InProgress)
			{
				FP_LOG(LogFP, Log, TEXT("%s"), TEXT("GetMatchState() == MatchState::InProgress"));
				FinishMatch();
			}
			else if (GetMatchState() == MatchState::WaitingPostMatch)
			{
				FP_LOG(LogFP, Log, TEXT("%s"), TEXT("GetMatchState() == MatchState::WaitingPostMatch"));
				GetWorld()->ServerTravel(TEXT("/Game/LevelDesign/Maps/LV_01_BombGame?listen"));
			}
		}
	}
}

void AFPGameMode::FinishMatch()
{
	FP_LOG(LogFP, Log, TEXT("%s"), TEXT("FinishMatch"));
	AFPGameState* const FPGameState = Cast<AFPGameState>(GameState);
	if (FPGameState && IsMatchInProgress())
	{
		EndMatch();
		FPGameState->RemainingTime = FPGameState->ShowResultWaitingTime;
	}
}
