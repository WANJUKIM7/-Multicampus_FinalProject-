// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FPLevelDatas.generated.h"

USTRUCT(BlueprintType)
struct FLevelBase
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector PlayerSpawnLocation = FVector(1000.0f, 1000.0f, 500.0f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector CameraSpawnLocation = FVector(-700.0f, 780.0f, 1000.0f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FRotator CameraSpawnRotation = FRotator(-40.0f, 0.0f, 0.0f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float TimeSpawnPortal = 0.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float TimeSpawnPlayer = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float TimeCountDownStarts = 3.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float TimeGameStarts = 8.0f;
};

USTRUCT(BlueprintType)
struct FLevel01
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector PlayerSpawnLocation = FVector(1000.0f, 1000.0f, 500.0f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector CameraSpawnLocation = FVector(-700.0f, 780.0f, 1000.0f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FRotator CameraSpawnRotation = FRotator(-40.0f, 0.0f, 0.0f);
};

USTRUCT(BlueprintType)
struct FLevel02
{
    GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector PlayerSpawnLocation = FVector(1000.0f, 1000.0f, 500.0f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector CameraSpawnLocation = FVector(-700.0f, 780.0f, 1000.0f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FRotator CameraSpawnRotation = FRotator(-40.0f, 0.0f, 0.0f);

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector SpotLightCenterLocation = FVector(500.0f, 500.0f, -260.0f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MaxXOffset = 1500.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MaxYOffset = 1500.0f;
};

USTRUCT(BlueprintType)
struct FLevel03
{
    GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector PlayerSpawnLocation = FVector(1000.0f, 1000.0f, 500.0f);

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float TimePlatformsBreakLoop = 3.0f;
};

USTRUCT(BlueprintType)
struct FLevel04
{
    GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector PlayerSpawnLocation = FVector(1000.0f, 1000.0f, 500.0f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector CameraSpawnLocation = FVector(-700.0f, 780.0f, 1000.0f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FRotator CameraSpawnRotation = FRotator(-40.0f, 0.0f, 0.0f);

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector RockSpawnLocationStart = FVector(1680.0f, 750.0f, 980.0f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector RockSpawnLocationEnd = FVector(1680.0f, 1910.0f, 980.0f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float TimeFirstPhaseSpawn = 0.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float TimeSecondPhaseSpawn = 0.2f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float TimeThirdPhaseSpawn = 0.1f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float TimeChangeSpawnLoop1 = 10.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float TimeChangeSpawnLoop2 = 20.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float TimeLife = 15.0f;
};

USTRUCT(BlueprintType)
struct FLevel05
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector PlayerSpawnLocation = FVector(1000.0f, 1000.0f, 500.0f);

	/*UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FTransform CameraSpawnTransform2 = FTransform();*/
};

USTRUCT(BlueprintType)
struct FLevel06
{
    GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector PlayerSpawnLocation = FVector(1000.0f, 1000.0f, 500.0f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector CameraSpawnLocation = FVector(-700.0f, 780.0f, 1000.0f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FRotator CameraSpawnRotation = FRotator(-40.0f, 0.0f, 0.0f);

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float TimeTrainLoopTime = 5.0f;
};

USTRUCT(BlueprintType)
struct FLevel07
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector PlayerSpawnLocation = FVector(1000.0f, 1000.0f, 500.0f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector CameraSpawnLocation = FVector(-700.0f, 780.0f, 1000.0f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FRotator CameraSpawnRotation = FRotator(-40.0f, 0.0f, 0.0f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FTransform CameraSpawnTransform2 = FTransform();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector WinLocation = FVector(0.0f, 0.0f, 0.0f);
};

USTRUCT(BlueprintType)
struct FLevel08
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector PlayerSpawnLocation = FVector(1000.0f, 1000.0f, 500.0f);
};

/**
 * 
 */
UCLASS()
class FINALPROJECT_API UFPLevelDatas : public UDataAsset
{
	GENERATED_BODY()
	
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FLevelBase LevelBase;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FLevel01 Level01;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FLevel02 Level02;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FLevel03 Level03;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FLevel04 Level04;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FLevel05 Level05;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FLevel06 Level06;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FLevel07 Level07;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FLevel08 Level08;
};
