// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/FP08RotateAuto.h"
#include "System/FPAssetManager.h"
#include "Data/FPLevelData.h"

// Sets default values
AFP08RotateAuto::AFP08RotateAuto()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Platform = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Platform"));
	RootComponent = Platform;
	Platform->SetRelativeScale3D(FVector(5.0f, 5.0f, 1.0f));
}

// Called when the game starts or when spawned
void AFP08RotateAuto::BeginPlay()
{
	Super::BeginPlay();
	
	// Set Mesh, Material
	if (const UFPLevelData* LevelData = UFPAssetManager::GetAssetByName<UFPLevelData>("LevelData"))
	{
		if (LevelData->Level08Assets[0].RotatingPlatform)
		{
			Platform->SetStaticMesh(LevelData->Level08Assets[0].RotatingPlatform);
			UE_LOG(LogTemp, Log, TEXT("RotatingPlatform Found!"));
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("RotatingPlatform Not Founded!"));
		}

		if (LevelData->Level08Assets[0].RotatingPlatformMaterial)
		{
			Platform->SetMaterial(0, LevelData->Level08Assets[0].RotatingPlatformMaterial);
		}

	}
}

// Called every frame
void AFP08RotateAuto::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AddActorLocalRotation(FRotator(0.0f, DeltaTime * RotationSpeed, 0.0f));
}

