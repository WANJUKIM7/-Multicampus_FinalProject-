// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/FP08RotateAuto.h"

// Sets default values
AFP08RotateAuto::AFP08RotateAuto()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Platform = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Platform"));
	RootComponent = Platform;
	Platform->SetRelativeScale3D(FVector(5.0f, 5.0f, 1.0f));

	ConstructorHelpers::FObjectFinder<UStaticMesh> FindMesh(TEXT(""));
	if (FindMesh.Succeeded())
	{
		Platform->SetStaticMesh(FindMesh.Object);
	}
}

// Called when the game starts or when spawned
void AFP08RotateAuto::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFP08RotateAuto::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AddActorLocalRotation(FRotator(0.0f, DeltaTime * RotationSpeed, 0.0f));
}

