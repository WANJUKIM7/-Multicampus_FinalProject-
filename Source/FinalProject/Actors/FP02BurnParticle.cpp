// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/FP02BurnParticle.h"
#include "Particles/ParticleSystemComponent.h"
#include "System/FPAssetManager.h"
#include "Data/FPLevelAssets.h"

// Sets default values
AFP02BurnParticle::AFP02BurnParticle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Particle
	Burn = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Burn"));
    RootComponent = Burn;
    Burn->bAutoActivate = true;
}

// Called when the game starts or when spawned
void AFP02BurnParticle::BeginPlay()
{
	Super::BeginPlay();

	// Set ParticleSystem
	if (const UFPLevelAssets* LevelData = UFPAssetManager::GetAssetByName<UFPLevelAssets>("LevelAsset"))
	{
		if (LevelData->Level02Assets[0].Fire)
		{
			Burn->SetTemplate(LevelData->Level02Assets[0].Fire);
			UE_LOG(LogTemp, Log, TEXT("Burn Found!"));
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Burn Founded!"));
		}

	}

	SetLifeSpan(0.6f);
}

// Called every frame
void AFP02BurnParticle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

