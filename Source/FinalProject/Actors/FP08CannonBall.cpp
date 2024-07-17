// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/FP08CannonBall.h"

// Sets default values
AFP08CannonBall::AFP08CannonBall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFP08CannonBall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFP08CannonBall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

