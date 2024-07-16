// Copyright Epic Games, Inc. All Rights Reserved.

#include "GameMode/FPGameMode.h"
#include "Character/FPCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Character/FPPlayerController.h"

AFPGameMode::AFPGameMode()
{
	// set default pawn class to our Blueprinted character
	/*static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Programming/ThirdPerson/Blueprints/BP_ThirdPersonCharacter.BP_ThirdPersonCharacter_C"));*/
	/*static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Script/FinalProject.FPPlayer"));*/
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Script/Engine.Blueprint'/Game/Programming/Blueprints/BP_Player.BP_Player_C'"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	PlayerControllerClass = AFPPlayerController::StaticClass();
}
