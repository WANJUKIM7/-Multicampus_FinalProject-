// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Levels/FPLevelBase.h"
#include "FPLevelDerived03.generated.h"

/**
 * 
 */
UCLASS()
class FINALPROJECT_API AFPLevelDerived03 : public AFPLevelBase
{
	GENERATED_BODY()

public:
	AFPLevelDerived03();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void SetMappingContext() override;
	virtual void SpawnCamera() override;
	virtual void SetSpawnValues() override;
public:
	void BreakPlatforms();

	/*UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TArray<TSubclassOf<class AFP03Platform>> Platforms;*/
	
	/*UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float TimePlatformsBreakLoop = 3.0f;*/
};
