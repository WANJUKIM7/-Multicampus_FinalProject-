// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/FPPortalDestroyPlayer.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
AFPPortalDestroyPlayer::AFPPortalDestroyPlayer()
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
void AFPPortalDestroyPlayer::BeginPlay()
{
	Super::BeginPlay();
	SetLifeSpan(3.0f);
}

// Called every frame
void AFPPortalDestroyPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

