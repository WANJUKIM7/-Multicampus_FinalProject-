// Fill out your copyright notice in the Description page of Project Settings.


#include "FP06Train.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AFP06Train::AFP06Train()
	: Speed(-25.0f)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Train = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Train"));
	RootComponent = Train;
	Train->SetRelativeScale3D(FVector(3.0f, 3.0f, 3.0f));

	ConstructorHelpers::FObjectFinder<UStaticMesh> FindMesh(TEXT("/Script/Engine.StaticMesh'/Game/LevelDesign/LevelPrototyping/Meshes/SM_ChamferCube.SM_ChamferCube'"));
	if (FindMesh.Succeeded())
	{
		Train->SetStaticMesh(FindMesh.Object);
	}
	Train->SetCollisionProfileName(FName("OverlapOnlyPawn"));
}

// Called when the game starts or when spawned
void AFP06Train::BeginPlay()
{
	Super::BeginPlay();
	

}

// Called every frame
void AFP06Train::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorLocalOffset(FVector(0.0f, -25.0f, 0.0f));
}

