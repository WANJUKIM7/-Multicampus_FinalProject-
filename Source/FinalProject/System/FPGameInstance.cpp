// Fill out your copyright notice in the Description page of Project Settings.


#include "System/FPGameInstance.h"
#include "FPAssetManager.h"

UFPGameInstance::UFPGameInstance(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UFPGameInstance::Init()
{
	Super::Init();

	UFPAssetManager::Initialize();
}

void UFPGameInstance::Shutdown()
{
	Super::Shutdown();
}
