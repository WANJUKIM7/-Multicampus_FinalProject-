// Copyright Epic Games, Inc. All Rights Reserved.

#include "GameMode/FPGameMode.h"
#include "Character/FPPlayer.h"
#include "UObject/ConstructorHelpers.h"
#include "Character/FPPlayerController.h"
#include "Kismet/GameplayStatics.h"

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
}

AFPPlayer* AFPGameMode::GetSpawnedPlayer() const
{
	return SpawnedPlayer;
}

void AFPGameMode::BeginPlay()
{
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, 0);
	if (PlayerController)
	{
		SpawnedPlayer = Cast<AFPPlayer>(PlayerController->GetPawn());
	}
}
