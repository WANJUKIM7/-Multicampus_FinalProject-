// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/FP05InclinePlatform.h"
#include "System/FPAssetManager.h"
#include "Data/FPLevelAssets.h"

// Sets default values
AFP05InclinePlatform::AFP05InclinePlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	InclinePlatform = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("InclinePlatform"));
	RootComponent = InclinePlatform;
	InclinePlatform->SetRelativeRotation(FRotator(0.0f, -10.0f, 90.0f));
	InclinePlatform->SetRelativeScale3D(FVector(1100.0f, 1000.0f, 1100.0f));
	InclinePlatform->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);
	InclinePlatform->SetCollisionProfileName(FName("PhysicsActor"));
	InclinePlatform->SetSimulatePhysics(true);
	if (FBodyInstance* BodyInst = InclinePlatform->GetBodyInstance())
	{
		BodyInst->SetMassScale(0.6f);
		BodyInst->UpdateMassProperties();
	}
}

// Called when the game starts or when spawned
void AFP05InclinePlatform::BeginPlay()
{
	Super::BeginPlay();
	// Set Mesh, Material
	if (const UFPLevelAssets* LevelData = UFPAssetManager::GetAssetByName<UFPLevelAssets>("LevelAsset"))
	{
		if (LevelData->Level05Assets[0].InclinePlatform)
		{
			InclinePlatform->SetStaticMesh(LevelData->Level05Assets[0].InclinePlatform);
			UE_LOG(LogTemp, Log, TEXT("InclinePlatform Found!"));
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("InclinePlatform Not Founded!"));
		}

		if (LevelData->Level05Assets[0].InclinePlatformMaterial0)
		{
			InclinePlatform->SetMaterial(0, LevelData->Level05Assets[0].InclinePlatformMaterial0);
		}

		if (LevelData->Level05Assets[0].InclinePlatformMaterial1)
		{
			InclinePlatform->SetMaterial(0, LevelData->Level05Assets[0].InclinePlatformMaterial1);
		}
	}
}

// Called every frame
void AFP05InclinePlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

