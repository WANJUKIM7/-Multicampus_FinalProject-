// Fill out your copyright notice in the Description page of Project Settings.


#include "Levels/FPLevelDerived06.h"

AFPLevelDerived06::AFPLevelDerived06()
{
}

void AFPLevelDerived06::BeginPlay()
{
	SetMappingContext();
	SetSpawnValues();

	Super::BeginPlay();

	/*if (Player)
	{
		Player->SetCurrentLevel(ECurrentLevel::E_Level06);
	}
	else
	{
		FP_LOG(LogFP, Warning, TEXT("%s"), TEXT("No Player"));
	}*/
}

void AFPLevelDerived06::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AFPLevelDerived06::SetMappingContext()
{
	PlayerController = Cast<AFPPlayerController>(UGameplayStatics::GetPlayerController(this, 0));
    PlayerController->ChangeMappingContextQuater();
    PlayerController->DisableInput(PlayerController);
}

void AFPLevelDerived06::SetSpawnValues()
{
	LevelDatas->LevelBase.CameraSpawnLocation = LevelDatas->Level06.CameraSpawnLocation;
	LevelDatas->LevelBase.CameraSpawnRotation = LevelDatas->Level06.CameraSpawnRotation;
	LevelDatas->LevelBase.PlayerSpawnLocation = LevelDatas->Level06.PlayerSpawnLocation;
}
