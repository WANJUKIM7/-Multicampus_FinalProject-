// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/FP07Destination.h"
#include "Components/BoxComponent.h"

// Sets default values
AFP07Destination::AFP07Destination()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	RootComponent = BoxCollision;
	BoxCollision->SetCollisionProfileName(TEXT("OverlapAll"));
	BoxCollision->SetRelativeScale3D(FVector(2.0f, 2.0f, 2.0f));
	BoxCollision->SetHiddenInGame(false);
}

// Called when the game starts or when spawned
void AFP07Destination::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFP07Destination::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

