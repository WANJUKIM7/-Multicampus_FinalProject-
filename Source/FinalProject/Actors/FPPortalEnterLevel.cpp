// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/FPPortalEnterLevel.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
AFPPortalEnterLevel::AFPPortalEnterLevel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Particle
	ParticleSystem = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleSystem"));
    ParticleSystem->SetupAttachment(RootComponent);
	ConstructorHelpers::FObjectFinder<UParticleSystem> FindParticle(TEXT(""));
	if (FindParticle.Succeeded())
	{
		ParticleSystem->SetTemplate(FindParticle.Object);
	}
    ParticleSystem->bAutoActivate = true;
}

// Called when the game starts or when spawned
void AFPPortalEnterLevel::BeginPlay()
{
	Super::BeginPlay();
	SetLifeSpan(4.0f);
}

// Called every frame
void AFPPortalEnterLevel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

