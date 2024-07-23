// Fill out your copyright notice in the Description page of Project Settings.


#include "Levels/FPLevelDerived07.h"

AFPLevelDerived07::AFPLevelDerived07()
	: Super()
{
}

void AFPLevelDerived07::BeginPlay()
{
	SetMappingContext();
	Super::BeginPlay();

	Player->SetCurrentLevel(ECurrentLevel::E_Level07);
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
