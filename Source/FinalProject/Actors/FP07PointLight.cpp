// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/FP07PointLight.h"

// Sets default values
AFP07PointLight::AFP07PointLight()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFP07PointLight::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFP07PointLight::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

