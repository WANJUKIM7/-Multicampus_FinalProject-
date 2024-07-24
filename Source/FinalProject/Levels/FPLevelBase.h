// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "Kismet/GameplayStatics.h"
#include "Character/FPPlayerController.h"
#include "Character/FPPlayer.h"
#include "Data/FPLevelDatas.h"
#include "GameMode/FPGameState.h"
#include "FPLevelBase.generated.h"

/**
 * 
 */
UCLASS()
class FINALPROJECT_API AFPLevelBase : public ALevelScriptActor
{
	GENERATED_BODY()

public:
	AFPLevelBase();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

protected:
	class AFPPlayer* GetPlayerFromGameMode();
	void StartFadeIn();
	void PlayerSetting();
	virtual void SetMappingContext();
	virtual void SpawnCamera();
	virtual void SetSpawnValues();
	void SetTimer();
	void SpawnPortal();
	void SpawnPlayer();
	void StartCountdown();
	void DestroyCountdownWidget();
	void PlayerControlable();
	void CheckGameState();
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TObjectPtr<class AFPPlayer> Player = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TObjectPtr<class ACameraActor> Camera = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TObjectPtr<class AFPPlayerController> PlayerController = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<class UWidgetComponent> Countdown = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TSubclassOf<class UUserWidget> CountdownWidgetClassReference = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TObjectPtr<class UFPLevelDatas> LevelDatas;
//private:
//	UPROPERTY()
//	TObjectPtr<AFPGameMode> GameMode;
};
