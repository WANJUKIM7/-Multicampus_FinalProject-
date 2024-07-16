// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "FPGameMode.generated.h"

class AFPPlayer;

UCLASS(minimalapi)
class AFPGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AFPGameMode();

	AFPPlayer* GetSpawnedPlayer() const;
protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY()
	AFPPlayer* SpawnedPlayer;
};



