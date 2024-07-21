// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/FP06Tail.h"
#include "Components/SplineComponent.h"

// Sets default values
AFP06Tail::AFP06Tail()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Tail = CreateDefaultSubobject<USplineComponent>(TEXT("Tail"));
    RootComponent = Tail;

    Tail->AddSplinePoint(FVector(0.0f, 0.0f, 0.0f), ESplineCoordinateSpace::Local, true);
    Tail->AddSplinePoint(FVector(100.0f, 0.0f, 0.0f), ESplineCoordinateSpace::Local, true);

    Tail->UpdateSpline();
}

// Called when the game starts or when spawned
void AFP06Tail::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFP06Tail::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

