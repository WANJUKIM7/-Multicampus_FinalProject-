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

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FVector RockSpawnLocationStart;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FVector RockSpawnLocationEnd;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float TimeFirstPhaseSpawn;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float TimeSecondPhaseSpawn;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float TimeThirdPhaseSpawn;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float TimeChangeSpawnLoop1;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float TimeChangeSpawnLoop2;
};
