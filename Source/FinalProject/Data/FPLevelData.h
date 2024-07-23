// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameplayTagContainer.h"
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FPLevelData.generated.h"

USTRUCT()
struct FPLeve01Assets
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
	FGameplayTag InputTag = FGameplayTag::EmptyTag;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UStaticMesh> Bomb;
	
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UMaterial> BombMaterial;

	UPROPERTY(EditDefaultsOnly)
    TObjectPtr<UParticleSystem> BombExplode;
};

USTRUCT()
struct FPLeve02Assets
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
	FGameplayTag InputTag = FGameplayTag::EmptyTag;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UParticleSystem> Fire;
};

USTRUCT()
struct FPLeve03Assets
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
	FGameplayTag InputTag = FGameplayTag::EmptyTag;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UStaticMesh> Platform;
	
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UMaterial> PlatformMaterial;
};

USTRUCT()
struct FPLeve04Assets
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
	FGameplayTag InputTag = FGameplayTag::EmptyTag;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UStaticMesh> Rock;
	
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UMaterial> RockMaterial;
};

USTRUCT()
struct FPLeve05Assets
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
	FGameplayTag InputTag = FGameplayTag::EmptyTag;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UStaticMesh> Ball;
	
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UMaterial> BallMaterial;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UStaticMesh> InclinePlatform;
	
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UMaterial> InclinePlatformMaterial;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UParticleSystem> HitEffect;
};

USTRUCT()
struct FPLeve06Assets
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
	FGameplayTag InputTag = FGameplayTag::EmptyTag;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UStaticMesh> Train;
	
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UMaterial> TrainMaterial0;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UMaterial> TrainMaterial1;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UMaterial> TrainMaterial2;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UMaterial> TrainMaterial3;
};

USTRUCT()
struct FPLeve08Assets
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
	FGameplayTag InputTag = FGameplayTag::EmptyTag;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UStaticMesh> CannonBall;
	
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UMaterial> CannonBallMaterial;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UParticleSystem> CannonBallEffect;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UStaticMesh> RotatingPlatform;
	
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UMaterial> RotatingPlatformMaterial;
};

USTRUCT()
struct FPAssetMeshes
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
	FGameplayTag InputTag = FGameplayTag::EmptyTag;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UStaticMesh> Mesh = nullptr;
};

USTRUCT()
struct FPAssetMaterials
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
	FGameplayTag InputTag = FGameplayTag::EmptyTag;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UMaterial> Material = nullptr;
};

USTRUCT()
struct FPAssetParticles
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
	FGameplayTag InputTag = FGameplayTag::EmptyTag;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UParticleSystem> Particle = nullptr;
};
/**
 * 
 */
UCLASS()
class FINALPROJECT_API UFPLevelData : public UDataAsset
{
	GENERATED_BODY()

public:
	const UStaticMesh* FindMeshesByTag(const FGameplayTag& InputTag) const;
	const UMaterial* FindMaterialsByTag(const FGameplayTag& InputTag) const;
	const UParticleSystem* FindParticlesByTag(const FGameplayTag& InputTag) const;
	
public:
	UPROPERTY(EditDefaultsOnly)
    TArray<FPLeve01Assets> Level01Assets;

	UPROPERTY(EditDefaultsOnly)
    TArray<FPLeve02Assets> Level02Assets;

	UPROPERTY(EditDefaultsOnly)
    TArray<FPLeve03Assets> Level03Assets;

	UPROPERTY(EditDefaultsOnly)
    TArray<FPLeve04Assets> Level04Assets;

	UPROPERTY(EditDefaultsOnly)
    TArray<FPLeve05Assets> Level05Assets;

	UPROPERTY(EditDefaultsOnly)
    TArray<FPLeve06Assets> Level06Assets;

	UPROPERTY(EditDefaultsOnly)
    TArray<FPLeve08Assets> Level08Assets;

	UPROPERTY(EditDefaultsOnly)
	TArray<FPAssetMeshes> AssetMeshes;

	UPROPERTY(EditDefaultsOnly)
	TArray<FPAssetMaterials> AssetMaterials;

	UPROPERTY(EditDefaultsOnly)
	TArray<FPAssetParticles> AssetParticles;
};
