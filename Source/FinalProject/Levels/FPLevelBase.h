// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
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
	void SetMappingContext();
	void SpawnCamera();
	void StartFadeIn();

	void TimerElapsed();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<class AFPPlayer> Player;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TObjectPtr<class ACameraActor> Camera;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TObjectPtr<class AFPPlayerController> PlayerController;
};
