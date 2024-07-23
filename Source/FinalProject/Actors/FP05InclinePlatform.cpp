// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/FP05InclinePlatform.h"
#include "System/FPAssetManager.h"
#include "Data/FPLevelData.h"

// Sets default values
AFP05InclinePlatform::AFP05InclinePlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	InclinePlatform = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("InclinePlatform"));
	RootComponent = InclinePlatform;
	InclinePlatform->SetRelativeScale3D(FVector(18.0f, 18.0f, 1.0f));
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
	if (const UFPLevelData* LevelData = UFPAssetManager::GetAssetByName<UFPLevelData>("LevelData"))
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

		if (LevelData->Level05Assets[0].InclinePlatformMaterial)
		{
			InclinePlatform->SetMaterial(0, LevelData->Level05Assets[0].InclinePlatformMaterial);
		}

	}
}

// Called every frame
void AFP05InclinePlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

