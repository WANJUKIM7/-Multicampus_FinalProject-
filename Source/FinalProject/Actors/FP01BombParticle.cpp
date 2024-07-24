// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/FP01BombParticle.h"
#include "Particles/ParticleSystemComponent.h"
#include "System/FPAssetManager.h"
#include "Data/FPLevelAssets.h"

// Sets default values
AFP01BombParticle::AFP01BombParticle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Particle
	Explode = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Explode"));
    RootComponent = Explode;
    Explode->bAutoActivate = true;
}

// Called when the game starts or when spawned
void AFP01BombParticle::BeginPlay()
{
	Super::BeginPlay();

	// Set ParticleSystem
	if (const UFPLevelAssets* LevelData = UFPAssetManager::GetAssetByName<UFPLevelAssets>("LevelAsset"))
	{
		if (LevelData->Level01Assets[0].BombExplode)
		{
			Explode->SetTemplate(LevelData->Level01Assets[0].BombExplode);
			UE_LOG(LogTemp, Log, TEXT("Bomb Explode Found!"));
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Bomb Explode Not Founded!"));
		}

	}

	SetLifeSpan(4.0f);
}

// Called every frame
void AFP01BombParticle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

