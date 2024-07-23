// Fill out your copyright notice in the Description page of Project Settings.


#include "FP06Train.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "System/FPAssetManager.h"
#include "Data/FPLevelData.h"

// Sets default values
AFP06Train::AFP06Train()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Train = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Train"));
	RootComponent = Train;
	Train->SetRelativeRotation(FRotator(0.0f, 180.0f, 0.0f));
	Train->SetRelativeScale3D(FVector(1.0f, 1.0f, 1.0f));
	Train->SetCollisionProfileName(FName("OverlapOnlyPawn"));
}

// Called when the game starts or when spawned
void AFP06Train::BeginPlay()
{
	Super::BeginPlay();
	
	// Set Mesh, Material
	if (const UFPLevelData* LevelData = UFPAssetManager::GetAssetByName<UFPLevelData>("LevelData"))
	{
		if (LevelData->Level06Assets[0].Train)
		{
			Train->SetStaticMesh(LevelData->Level06Assets[0].Train);
			UE_LOG(LogTemp, Log, TEXT("Train Found!"));
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Train Not Founded!"));
		}

		if (LevelData->Level06Assets[0].TrainMaterial0)
		{
			Train->SetMaterial(0, LevelData->Level06Assets[0].TrainMaterial0);
		}
		if (LevelData->Level06Assets[0].TrainMaterial1)
		{
			Train->SetMaterial(0, LevelData->Level06Assets[0].TrainMaterial1);
		}
		if (LevelData->Level06Assets[0].TrainMaterial2)
		{
			Train->SetMaterial(0, LevelData->Level06Assets[0].TrainMaterial2);
		}
		if (LevelData->Level06Assets[0].TrainMaterial3)
		{
			Train->SetMaterial(0, LevelData->Level06Assets[0].TrainMaterial3);
		}
	}
}

// Called every frame
void AFP06Train::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorLocalOffset(FVector(0.0f, Speed, 0.0f));
}

