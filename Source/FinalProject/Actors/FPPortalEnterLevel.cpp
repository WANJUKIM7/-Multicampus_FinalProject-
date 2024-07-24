// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/FPPortalEnterLevel.h"
#include "Particles/ParticleSystemComponent.h"
#include "System/FPAssetManager.h"
#include "Data/FPLevelAssets.h"
#include "NiagaraComponent.h"

// Sets default values
AFPPortalEnterLevel::AFPPortalEnterLevel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Particle
	PortalEnter = CreateDefaultSubobject<UNiagaraComponent>(TEXT("PortalEnter"));
    RootComponent = PortalEnter;
	PortalEnter->SetRelativeScale3D(FVector(0.0f, 0.0f, 0.0f));
    PortalEnter->bAutoActivate = true;
}

// Called when the game starts or when spawned
void AFPPortalEnterLevel::BeginPlay()
{
	Super::BeginPlay();

	// Set ParticleSystem
	if (const UFPLevelAssets* LevelData = UFPAssetManager::GetAssetByName<UFPLevelAssets>("LevelAsset"))
	{
		if (LevelData->LevelBaseAssets[0].PortalEnter)
		{
			PortalEnter->SetAsset(LevelData->LevelBaseAssets[0].PortalEnter);
			UE_LOG(LogTemp, Log, TEXT("PortalEnter Found!"));
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("PortalEnter Not Founded!"));
		}

	}
}

// Called every frame
void AFPPortalEnterLevel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ElapsedTime += DeltaTime;

	if (bIsScalingUp)
	{
		float Scale = FMath::Clamp(ElapsedTime, 0.0f, 1.0f);
		PortalEnter->SetWorldScale3D(FVector(Scale));

		if (ElapsedTime >= 1.0f)
		{
			bIsScalingUp = false;
			ElapsedTime = 0.0f;
		}
	}
	else if (!bIsScalingDown && ElapsedTime >= 1.0f)
	{
		ElapsedTime = 0.0f;
		bIsScalingDown = true;
	}
	else if (bIsScalingDown)
	{
		float Scale = FMath::Clamp(1.0f - ElapsedTime, 0.0f, 1.0f);
		PortalEnter->SetWorldScale3D(FVector(Scale));

		if (ElapsedTime >= 1.0f)
		{
			bIsScalingDown = false;
			Destroy();
		}
	}
}
