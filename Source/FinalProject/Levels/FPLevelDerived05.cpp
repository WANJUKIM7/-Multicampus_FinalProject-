// Fill out your copyright notice in the Description page of Project Settings.


#include "Levels/FPLevelDerived05.h"

AFPLevelDerived05::AFPLevelDerived05()
{
}

void AFPLevelDerived05::BeginPlay()
{
	SetMappingContext();
	SetSpawnValues();
	Super::BeginPlay();

	Player->SetCurrentLevel(ECurrentLevel::E_Level05);
	Player->SetMovementAccerlation(500.0f);
	Player->SetMovementGroundFriction(0.2f);

	LevelDatas->LevelBase.PlayerSpawnLocation = FVector(0.0f, 0.0f, 0.0f);

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

void AFPLevelDerived05::SetSpawnValues()
{
	LevelDatas->LevelBase.PlayerSpawnLocation = LevelDatas->Level02.PlayerSpawnLocation;
}
