// Copyright Epic Games, Inc. All Rights Reserved.

#include "FinalProjectGameMode.h"
#include "FinalProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

AFinalProjectGameMode::AFinalProjectGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Programming/ThirdPerson/Blueprints/BP_ThirdPersonCharacter_C"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
