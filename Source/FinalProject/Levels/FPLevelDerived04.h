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
	virtual void SetSpawnValues() override;
	/*UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FVector RockSpawnLocationStart = FVector(1680.0f, 750.0f, 980.0f);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FVector RockSpawnLocationEnd = FVector(1680.0f, 1910.0f, 980.0f);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float TimeFirstPhaseSpawn = 0.5f;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float TimeSecondPhaseSpawn = 0.2f;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float TimeThirdPhaseSpawn = 0.1f;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float TimeChangeSpawnLoop1 = 10.0f;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float TimeChangeSpawnLoop2 = 20.0f;*/
};
