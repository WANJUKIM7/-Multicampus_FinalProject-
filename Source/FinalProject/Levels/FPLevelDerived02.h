// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Levels/FPLevelBase.h"
#include "FPLevelDerived02.generated.h"

/**
 * 
 */
UCLASS()
class FINALPROJECT_API AFPLevelDerived02 : public AFPLevelBase
{
	GENERATED_BODY()
	
public:
	AFPLevelDerived02();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void SetMappingContext() override;
	virtual void SetSpawnValues() override;
public:
	void DarkChange();
	void SpawnSpotLight();
	void Phase2SpawnTimeSpotLight();
	void Phase3SpawnTimeSpotLight();
	void SetTimer();

	/*UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FVector SpotLightCenterLocation = FVector(500.0f, 500.0f, -260.0f);*/

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FTimerHandle SpawnSpotLightHandle;

	UPROPERTY()
	TSubclassOf<class AFP02Spotlight> ActorClass;
};
