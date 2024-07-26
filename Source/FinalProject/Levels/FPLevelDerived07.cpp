// Fill out your copyright notice in the Description page of Project Settings.


#include "Levels/FPLevelDerived07.h"

AFPLevelDerived07::AFPLevelDerived07()
{
}

void AFPLevelDerived07::BeginPlay()
{
	SetMappingContext();
	SetSpawnValues();

	Super::BeginPlay();

	/*if (Player)
	{
		Player->SetCurrentLevel(ECurrentLevel::E_Level07);
	}
	else
	{
		FP_LOG(LogFP, Warning, TEXT("%s"), TEXT("No Player"));
	}*/
}

void AFPLevelDerived07::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AFPLevelDerived07::SetMappingContext()
{
	PlayerController = Cast<AFPPlayerController>(UGameplayStatics::GetPlayerController(this, 0));
    PlayerController->ChangeMappingContextQuater();
    PlayerController->DisableInput(PlayerController);
}

void AFPLevelDerived07::SetSpawnValues()
{
	LevelDatas->LevelBase.CameraSpawnLocation = LevelDatas->Level07.CameraSpawnLocation;
	LevelDatas->LevelBase.CameraSpawnRotation = LevelDatas->Level07.CameraSpawnRotation;
	LevelDatas->LevelBase.PlayerSpawnLocation = LevelDatas->Level07.PlayerSpawnLocation;
}
