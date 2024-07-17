// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Levels/FPLevelBase.h"
#include "FPLevelDerived04.generated.h"

/**
 * 
 */
UCLASS()
class FINALPROJECT_API AFPLevelDerived04 : public AFPLevelBase
{
	GENERATED_BODY()
	
public:
	AFPLevelDerived04();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void SetMappingContext() override;
};
