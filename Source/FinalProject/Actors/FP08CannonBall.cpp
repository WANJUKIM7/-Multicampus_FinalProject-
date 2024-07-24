// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/FP08CannonBall.h"
#include "System/FPAssetManager.h"
#include "Data/FPLevelAssets.h"

// Sets default values
AFP08CannonBall::AFP08CannonBall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CannonBall = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CannonBall"));
	RootComponent = CannonBall;
	CannonBall->SetSimulatePhysics(true);
	
}

// Called when the game starts or when spawned
void AFP08CannonBall::BeginPlay()
{
	Super::BeginPlay();
	// Set Mesh, Material
	if (const UFPLevelAssets* LevelData = UFPAssetManager::GetAssetByName<UFPLevelAssets>("LevelAsset"))
	{
		if (LevelData->Level08Assets[0].CannonBall)
		{
			CannonBall->SetStaticMesh(LevelData->Level08Assets[0].CannonBall);
			UE_LOG(LogTemp, Log, TEXT("CannonBall Found!"));
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("CannonBall Not Founded!"));
		}

		if (LevelData->Level08Assets[0].CannonBallMaterial)
		{
			CannonBall->SetMaterial(0, LevelData->Level08Assets[0].CannonBallMaterial);
		}

	}
}

// Called every frame
void AFP08CannonBall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

