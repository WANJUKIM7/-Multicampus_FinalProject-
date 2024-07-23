// Fill out your copyright notice in the Description page of Project Settings.


#include "Levels/FPLevelDerived04.h"

AFPLevelDerived04::AFPLevelDerived04()
{
	
}

void AFPLevelDerived04::BeginPlay()
{
	SetMappingContext();
	SetSpawnValues();
	Super::BeginPlay();

	Player->SetCurrentLevel(ECurrentLevel::E_Level04);
	LevelDatas->LevelBase.CameraSpawnLocation = FVector(1340.0f, 1390.0f, 570.0f);
	LevelDatas->LevelBase.CameraSpawnRotation = FRotator(-40.0f, 0.0f, 0.0f);
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

void AFPLevelDerived04::SetSpawnValues()
{
	LevelDatas->LevelBase.CameraSpawnLocation = LevelDatas->Level04.CameraSpawnLocation;
	LevelDatas->LevelBase.CameraSpawnRotation = LevelDatas->Level04.CameraSpawnRotation;
	LevelDatas->LevelBase.PlayerSpawnLocation = LevelDatas->Level04.PlayerSpawnLocation;
}
