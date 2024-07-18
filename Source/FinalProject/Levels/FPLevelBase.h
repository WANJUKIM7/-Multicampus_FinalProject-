// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "Kismet/GameplayStatics.h"
#include "Character/FPPlayerController.h"
#include "Character/FPPlayer.h"
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
	void SetTimer();
	void SpawnPlayer();
	void StartCountdown();
	void DestroyCountdownWidget();
	void PlayerControlable();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<class AFPPlayer> Player;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TObjectPtr<class ACameraActor> Camera;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TObjectPtr<class AFPPlayerController> PlayerController;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<class UWidgetComponent> Countdown;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TSubclassOf<class UUserWidget> CountdownWidgetClassReference;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FVector PlayerSpawnLocation;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FVector CameraSpawnLocation;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float TimeSpawnPlayer;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float TimeCountDownStarts;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float TimeGameStarts;
};
