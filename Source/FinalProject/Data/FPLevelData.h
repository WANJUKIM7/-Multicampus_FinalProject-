// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameplayTagContainer.h"
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FPLevelData.generated.h"

USTRUCT()
struct FPLevelBaseAssets
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
	FGameplayTag InputTag = FGameplayTag::EmptyTag;

	UPROPERTY(EditDefaultsOnly)
    TObjectPtr<class UNiagaraSystem> PortalEnter;
};

USTRUCT()
struct FPLevel01Assets
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
struct FPLevel02Assets
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
	FGameplayTag InputTag = FGameplayTag::EmptyTag;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UParticleSystem> Fire;
};

USTRUCT()
struct FPLevel03Assets
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
struct FPLevel04Assets
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
struct FPLevel05Assets
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
struct FPLevel06Assets
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
struct FPLevel08Assets
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
    TArray<FPLevelBaseAssets> LevelBaseAssets;

	UPROPERTY(EditDefaultsOnly)
    TArray<FPLevel01Assets> Level01Assets;

	UPROPERTY(EditDefaultsOnly)
    TArray<FPLevel02Assets> Level02Assets;

	UPROPERTY(EditDefaultsOnly)
    TArray<FPLevel03Assets> Level03Assets;

	UPROPERTY(EditDefaultsOnly)
    TArray<FPLevel04Assets> Level04Assets;

	UPROPERTY(EditDefaultsOnly)
    TArray<FPLevel05Assets> Level05Assets;

	UPROPERTY(EditDefaultsOnly)
    TArray<FPLevel06Assets> Level06Assets;

	UPROPERTY(EditDefaultsOnly)
    TArray<FPLevel08Assets> Level08Assets;

	UPROPERTY(EditDefaultsOnly)
	TArray<FPAssetMeshes> AssetMeshes;

	UPROPERTY(EditDefaultsOnly)
	TArray<FPAssetMaterials> AssetMaterials;

	UPROPERTY(EditDefaultsOnly)
	TArray<FPAssetParticles> AssetParticles;
};
