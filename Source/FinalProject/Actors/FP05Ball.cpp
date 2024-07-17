// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/FP05Ball.h"

// Sets default values
AFP05Ball::AFP05Ball()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFP05Ball::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFP05Ball::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

