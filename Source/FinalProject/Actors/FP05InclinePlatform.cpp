// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/FP05InclinePlatform.h"

// Sets default values
AFP05InclinePlatform::AFP05InclinePlatform()
	: InclineValue(10.0f)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	InclinePlatform = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("InclinePlatform"));
	RootComponent = InclinePlatform;
	InclinePlatform->SetRelativeScale3D(FVector(18.0f, 18.0f, 1.0f));

	ConstructorHelpers::FObjectFinder<UStaticMesh> FindMesh(TEXT("/Script/Engine.StaticMesh'/Game/LevelDesign/LevelPrototyping/Meshes/SM_Cylinder.SM_Cylinder'"));
	if (FindMesh.Succeeded())
	{
		InclinePlatform->SetStaticMesh(FindMesh.Object);
	}
	InclinePlatform->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);
	InclinePlatform->SetCollisionProfileName(FName("PhysicsActor"));
	InclinePlatform->SetSimulatePhysics(true);
}

// Called when the game starts or when spawned
void AFP05InclinePlatform::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFP05InclinePlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

