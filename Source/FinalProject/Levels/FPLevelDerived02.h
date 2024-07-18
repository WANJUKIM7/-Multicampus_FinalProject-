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

public:
	void SpawnPlayerHPUI();
	void DarkChange();
	void SpawnSpotLight();
	void Phase2SpawnTimeSpotLight();
	void Phase3SpawnTimeSpotLight();
	void SetTimer();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<class UWidgetComponent> PlayerHP;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TSubclassOf<class UUserWidget> PlayerHPWidgetClassReference;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FVector SpotLightCenterLocation;

	UPROPERTY()
	FTimerHandle SpawnSpotLightHandle;
};
