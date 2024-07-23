// Fill out your copyright notice in the Description page of Project Settings.


#include "Levels/FPLevelDerived04.h"

AFPLevelDerived04::AFPLevelDerived04()
{
	CameraSpawnLocation = FVector(1340.0f, 1390.0f, 570.0f);
	CameraSpawnRotation = FRotator(-40.0f, 0.0f, 0.0f);
}

void AFPLevelDerived04::BeginPlay()
{
	SetMappingContext();
	Super::BeginPlay();
}

void AFPLevelDerived04::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AFPLevelDerived04::SetMappingContext()
{
	PlayerController = Cast<AFPPlayerController>(UGameplayStatics::GetPlayerController(this, 0));
    PlayerController->ChangeMappingContextQuaterJump();
    PlayerController->DisableInput(PlayerController);
}
