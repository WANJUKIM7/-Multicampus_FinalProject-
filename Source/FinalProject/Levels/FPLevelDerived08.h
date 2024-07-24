// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Levels/FPLevelBase.h"
#include "FPLevelDerived08.generated.h"

/**
 * 
 */
UCLASS()
class FINALPROJECT_API AFPLevelDerived08 : public AFPLevelBase
{
	GENERATED_BODY()
	
public:
	AFPLevelDerived08();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void SetMappingContext() override;
	virtual void SpawnCamera() override;
	virtual void SetSpawnValues() override;
};
