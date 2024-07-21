// Fill out your copyright notice in the Description page of Project Settings.


#include "Levels/FPLevelDerived01.h"
#include "Actors/FP01Bomb.h"

AFPLevelDerived01::AFPLevelDerived01()
	: Super()
	, Bomb(nullptr)
	, BombClass(nullptr)
{
	CameraSpawnLocation = FVector(0.0f, 800.0f, 300.0f);
}

void AFPLevelDerived01::BeginPlay()
{
	SetMappingContext();
	Super::BeginPlay();

	FTimerHandle SpawnBomb;

    GetWorldTimerManager().SetTimer(
        SpawnBomb, this, &AFPLevelDerived01::SpawnBomb, TimeGameStarts, false);
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

void AFPLevelDerived01::SpawnBomb()
{
	FTransform Transform(FRotator{ 0.0f, 0.0f, 0.0f }, FVector{ 0.0f, 0.0f, 0.0f }, FVector{ 1.0f, 1.0f, 1.0f });
	//Bomb = Cast<FP01Bomb>(GetWorld()->SpawnActor(BombClass));
	if (Bomb = GetWorld()->SpawnActor<AFP01Bomb>())
	{
		Bomb->AttachToComponent(Player.Get()->GetMesh(),FAttachmentTransformRules::KeepRelativeTransform, FName("bomb"));
		Player->SetIsAttachedBomb(true);
		//Player->SetViewReduction();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Bomb no spawned!"));
	}
}
