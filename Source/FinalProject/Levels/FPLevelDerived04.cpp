// Fill out your copyright notice in the Description page of Project Settings.


#include "Levels/FPLevelDerived04.h"

AFPLevelDerived04::AFPLevelDerived04()
	: Super()
	, RockSpawnLocationStart(1680.0f, 750.0f, 980.0f)
	, RockSpawnLocationEnd(1680.0f, 1910.0f, 980.0f)
	, TimeFirstPhaseSpawn(0.5f)
	, TimeSecondPhaseSpawn(0.2f)
	, TimeThirdPhaseSpawn(0.1f)
	, TimeChangeSpawnLoop1(10.0f)
	, TimeChangeSpawnLoop2(20.0f)
{
	CameraSpawnLocation = FVector(-880.0f, 1310.0f, 1000.0f);
	CameraSpawnRotation = FRotator(0.0f, 0.0f, 0.0f);
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
