// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Levels/FPLevelBase.h"
#include "FPLevelDerived01.generated.h"

/**
 * 
 */
UCLASS()
class FINALPROJECT_API AFPLevelDerived01 : public AFPLevelBase
{
	GENERATED_BODY()
	
public:
	AFPLevelDerived01();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

public:
	virtual void InitializeLevelSettings() override;

protected:
	virtual void SetMappingContext() override;
	virtual void SetSpawnValues() override;
public:
	void SpawnBomb();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TObjectPtr<class AFP01Bomb> Bomb = nullptr;

	UPROPERTY(VisibleAnywhere)
	TSubclassOf<AFP01Bomb> BombClass = nullptr;
};
