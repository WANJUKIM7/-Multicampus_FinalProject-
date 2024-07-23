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
	void SpawnPortal();
	void SpawnPlayer();
	void StartCountdown();
	void DestroyCountdownWidget();
	void PlayerControlable();

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

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FVector PlayerSpawnLocation = FVector(1000.0f, 1000.0f, 500.0f);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FVector CameraSpawnLocation = FVector(-700.0f, 780.0f, 1000.0f);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FRotator CameraSpawnRotation = FRotator(-40.0f, 0.0f, 0.0f);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float TimeSpawnPortal = 0.5f;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float TimeSpawnPlayer = 1.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float TimeCountDownStarts = 3.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float TimeGameStarts = 8.0f;
};
