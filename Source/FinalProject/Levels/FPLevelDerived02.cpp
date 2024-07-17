// Fill out your copyright notice in the Description page of Project Settings.


#include "Levels/FPLevelDerived02.h"

AFPLevelDerived02::AFPLevelDerived02()
	: Super()
{
}

void AFPLevelDerived02::BeginPlay()
{
	SetMappingContext();
	Super::BeginPlay();
}

void AFPLevelDerived02::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AFPLevelDerived02::SetMappingContext()
{
	PlayerController = Cast<AFPPlayerController>(UGameplayStatics::GetPlayerController(this, 0));
    PlayerController->ChangeMappingContextQuater();
    PlayerController->DisableInput(PlayerController);
}
