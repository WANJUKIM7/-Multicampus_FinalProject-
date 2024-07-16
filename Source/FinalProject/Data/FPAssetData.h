// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FPAssetData.generated.h"

USTRUCT()
struct FAssetEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
		FName AssetName;

	UPROPERTY(EditDefaultsOnly)
		FSoftObjectPath AssetPath;

	UPROPERTY(EditDefaultsOnly)
		TArray<FName> AssetLabels;
};

USTRUCT()
struct FAssetSet
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
		TArray<FAssetEntry> AssetEntries;

};

UCLASS()
class FINALPROJECT_API UFPAssetData : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
public:
	// Execute when save UPrimaryDataAsset.
	virtual void PreSave(FObjectPreSaveContext ObjectSaveContext) override;

public:
	FSoftObjectPath GetAssetPathByName(const FName& AssetName);
	const FAssetSet& GetAssetSetByLabel(const FName& Label);

private:
	UPROPERTY(EditDefaultsOnly)
	TMap<FName, FAssetSet> AssetGroupNameToSet;

	UPROPERTY()
	TMap<FName, FSoftObjectPath> AssetNameToPath;

	UPROPERTY()
	TMap<FName, FAssetSet> AssetLabelToSet;
};
