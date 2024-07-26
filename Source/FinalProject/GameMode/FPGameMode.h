// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Interface/FPGameInterface.h"
#include "GameFramework/GameMode.h"
#include "FPGameMode.generated.h"

class AFPPlayer;

UCLASS(minimalapi)
class AFPGameMode : public AGameMode, public IFPGameInterface
{
	GENERATED_BODY()

public:
	AFPGameMode();

	virtual FTransform GetRandomStartTransform() const;
	virtual void OnPlayerDead();

	/*virtual void PreLogin(const FString& Options, const FString& Address, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage) override;
	virtual APlayerController* Login(UPlayer* NewPlayer, ENetRole InRemoteRole, const FString& Portal, const FString& Options, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage) override;
	virtual void PostLogin(APlayerController* NewPlayer) override;*/
	virtual void StartPlay() override;
	void InitializeLevelSettings();
	//void GetSpawnedPlayer();

	/*UPROPERTY()
	AFPPlayer* SpawnedPlayer;*/
protected:
	virtual void PostInitializeComponents() override;
	virtual void DefaultGameTimer();
	void FinishMatch();

	FTimerHandle GameTimerHandle;

protected:
	TArray<TObjectPtr<class APlayerStart>> PlayerStartArray;
};
