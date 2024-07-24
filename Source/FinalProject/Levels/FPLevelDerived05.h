// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Levels/FPLevelBase.h"
#include "FPLevelDerived05.generated.h"

/**
 * 
 */
UCLASS()
class FINALPROJECT_API AFPLevelDerived05 : public AFPLevelBase
{
	GENERATED_BODY()
	
public:
	AFPLevelDerived05();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void SetMappingContext() override;
	virtual void SpawnCamera() override;
	virtual void SetSpawnValues() override;
};
