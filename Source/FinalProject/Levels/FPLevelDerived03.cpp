// Fill out your copyright notice in the Description page of Project Settings.


#include "Levels/FPLevelDerived03.h"

AFPLevelDerived03::AFPLevelDerived03()
	: Super()
{
}

void AFPLevelDerived03::BeginPlay()
{
	SetMappingContext();
	Super::BeginPlay();
}

void AFPLevelDerived03::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AFPLevelDerived03::SetMappingContext()
{
	PlayerController = Cast<AFPPlayerController>(UGameplayStatics::GetPlayerController(this, 0));
    PlayerController->ChangeMappingContextThirdPersonDoubleJumpInteraction();
    PlayerController->DisableInput(PlayerController);
}

void AFPLevelDerived03::SpawnCamera()
{
}
