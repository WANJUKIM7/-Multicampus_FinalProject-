// Fill out your copyright notice in the Description page of Project Settings.


#include "Levels/FPLevelDerived01.h"

AFPLevelDerived01::AFPLevelDerived01()
	: Super()
{
}

void AFPLevelDerived01::BeginPlay()
{
	SetMappingContext();
	Super::BeginPlay();
}

void AFPLevelDerived01::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AFPLevelDerived01::SetMappingContext()
{
	PlayerController = Cast<AFPPlayerController>(UGameplayStatics::GetPlayerController(this, 0));
    PlayerController->ChangeMappingContextQuaterJumpInteraction();
    PlayerController->DisableInput(PlayerController);
}
