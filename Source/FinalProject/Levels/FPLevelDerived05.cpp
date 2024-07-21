// Fill out your copyright notice in the Description page of Project Settings.


#include "Levels/FPLevelDerived05.h"

AFPLevelDerived05::AFPLevelDerived05()
	: Super()
{
	PlayerSpawnLocation = FVector(0.0f, 0.0f, 0.0f);
}

void AFPLevelDerived05::BeginPlay()
{
	SetMappingContext();
	Super::BeginPlay();
}

void AFPLevelDerived05::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AFPLevelDerived05::SetMappingContext()
{
	PlayerController = Cast<AFPPlayerController>(UGameplayStatics::GetPlayerController(this, 0));
    PlayerController->ChangeMappingContextThirdPerson();
    PlayerController->DisableInput(PlayerController);
}

void AFPLevelDerived05::SpawnCamera()
{
}
