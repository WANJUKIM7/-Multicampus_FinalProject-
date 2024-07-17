// Fill out your copyright notice in the Description page of Project Settings.


#include "Levels/FPLevelDerived04.h"

AFPLevelDerived04::AFPLevelDerived04()
	: Super()
{
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
