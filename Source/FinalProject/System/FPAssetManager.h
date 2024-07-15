// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "FPAssetManager.generated.h"

/**
 * 
 */
UCLASS()
class FINALPROJECT_API UFPAssetManager : public UAssetManager
{
	GENERATED_BODY()

public:
	UFPAssetManager();

	static UFPAssetManager& Get();
	
};
