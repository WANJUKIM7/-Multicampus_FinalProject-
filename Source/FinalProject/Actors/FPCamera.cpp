// Fill out your copyright notice in the Description page of Project Settings.


#include "FPCamera.h"

AFPCamera::AFPCamera()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AFPCamera::BeginPlay()
{
	Super::BeginPlay();
}

void AFPCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
