// Fill out your copyright notice in the Description page of Project Settings.


#include "Levels/FPLevelDerived08.h"

AFPLevelDerived08::AFPLevelDerived08()
    : Super()
{
}

void AFPLevelDerived08::BeginPlay()
{
    SetMappingContext();
    Super::BeginPlay();

    Player->SetCurrentLevel(ECurrentLevel::E_Level08);
}

void AFPLevelDerived08::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AFPLevelDerived08::SetMappingContext()
{
	PlayerController = Cast<AFPPlayerController>(UGameplayStatics::GetPlayerController(this, 0));
    PlayerController->ChangeMappingContextThirdPersonDoubleJumpInteraction();
    PlayerController->DisableInput(PlayerController);
}

void AFPLevelDerived08::SpawnCamera()
{
}
