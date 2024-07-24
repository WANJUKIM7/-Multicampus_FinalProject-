// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/FP05Ball.h"
#include "System/FPAssetManager.h"
#include "Data/FPLevelAssets.h"

// Sets default values
AFP05Ball::AFP05Ball()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Ball = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ball"));
	RootComponent = Ball;
	Ball->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);
	Ball->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
}

// Called when the game starts or when spawned
void AFP05Ball::BeginPlay()
{
	Super::BeginPlay();
	// Set Mesh, Material
	if (const UFPLevelAssets* LevelData = UFPAssetManager::GetAssetByName<UFPLevelAssets>("LevelAsset"))
	{
		if (LevelData->Level05Assets[0].Ball)
		{
			Ball->SetStaticMesh(LevelData->Level05Assets[0].Ball);
			UE_LOG(LogTemp, Log, TEXT("Ball Found!"));
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Ball Not Founded!"));
		}

		if (LevelData->Level05Assets[0].BallMaterial)
		{
			Ball->SetMaterial(0, LevelData->Level05Assets[0].BallMaterial);
		}

	}
}

// Called every frame
void AFP05Ball::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

