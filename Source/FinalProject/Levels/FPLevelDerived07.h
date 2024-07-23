// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Levels/FPLevelBase.h"
#include "FPLevelDerived07.generated.h"

/**
 * 
 */
UCLASS()
class FINALPROJECT_API AFPLevelDerived07 : public AFPLevelBase
{
	GENERATED_BODY()

public:
	AFPLevelDerived07();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void SetMappingContext() override;
	virtual void SetSpawnValues() override;
};
