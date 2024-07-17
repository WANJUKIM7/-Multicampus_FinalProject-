// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/FP01Bomb.h"

// Sets default values
AFP01Bomb::AFP01Bomb()
	: Super()
	, bInteracting(false)
	, TimeExplode(10.0f)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Bomb = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Bomb"));
	RootComponent = Bomb;
	Bomb->SetRelativeScale3D(FVector(0.1f, 0.1f, 0.1f));

	ConstructorHelpers::FObjectFinder<UStaticMesh> FindMesh(TEXT("/Script/Engine.StaticMesh'/Game/LevelDesign/LevelPrototyping/Meshes/SM_ChamferCube.SM_ChamferCube'"));
	if (FindMesh.Succeeded())
	{
		Bomb->SetStaticMesh(FindMesh.Object);
	}
}

// Called when the game starts or when spawned
void AFP01Bomb::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFP01Bomb::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TimeExplode -= DeltaTime;
	if (TimeExplode <= 0.0f)
	{
		SetActorTickEnabled(false);
		Destroy();
		//GetAttachParentActor()->Destroy();
		UE_LOG(LogTemp, Log, TEXT("Bomb Exploded!"));
	}
}

void AFP01Bomb::ResetTimer()
{
	TimeExplode = 10.0f;
}

