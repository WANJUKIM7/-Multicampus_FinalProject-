// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/FP01BombParticle.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
AFP01BombParticle::AFP01BombParticle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Particle
	ParticleSystem = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleSystem"));
    ParticleSystem->SetupAttachment(RootComponent);
	ConstructorHelpers::FObjectFinder<UParticleSystem> FindParticle(TEXT("/Script/Engine.ParticleSystem'/Game/contents/VFX/Realistic_Starter_VFX_Pack_Vol2/Particles/Explosion/P_Explosion_Big_A.P_Explosion_Big_A'"));
	if (FindParticle.Succeeded())
	{
		ParticleSystem->SetTemplate(FindParticle.Object);
	}
    ParticleSystem->bAutoActivate = true;
}

// Called when the game starts or when spawned
void AFP01BombParticle::BeginPlay()
{
	Super::BeginPlay();
	SetLifeSpan(4.0f);
}

// Called every frame
void AFP01BombParticle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

