// Fill out your copyright notice in the Description page of Project Settings.


#include "Levels/FPLevelDerived06.h"

AFPLevelDerived06::AFPLevelDerived06()
	: Super()
	, TimeTrainLoopTime(5.0f)
{
}

void AFPLevelDerived06::BeginPlay()
{
	SetMappingContext();
	Super::BeginPlay();
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
