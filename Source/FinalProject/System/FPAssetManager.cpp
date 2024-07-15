// Fill out your copyright notice in the Description page of Project Settings.


#include "System/FPAssetManager.h"
#include "FPLogChannels.h"

UFPAssetManager::UFPAssetManager() : Super()
{
}

UFPAssetManager& UFPAssetManager::Get()
{
	if (UFPAssetManager* Singleton = Cast<UFPAssetManager>(GEngine->AssetManager))
	{
		return *Singleton;
	}

	UE_LOG(LogFP, Fatal, TEXT("Can't find UFPAssetManager"));

	return *NewObject<UFPAssetManager>();
}
