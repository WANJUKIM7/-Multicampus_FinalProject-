// Fill out your copyright notice in the Description page of Project Settings.


#include "Levels/FPLevelBase.h"
#include "Character/FPPlayer.h"
#include "GameMode/FPGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Camera/CameraActor.h"
#include "Character/FPPlayerController.h"

AFPLevelBase::AFPLevelBase()
	:Player(nullptr)
{
}

void AFPLevelBase::BeginPlay()
{
    // Get the player character
    Player = GetPlayerFromGameMode();
    if (Player)
    {
        Player->GetController();
        UE_LOG(LogTemp, Log, TEXT("Player obtained from GameMode: %s"), *Player->GetName());
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Player doesn't get"));
    }

    SetMappingContext();
    SpawnCamera();
    //StartFadeIn();
    PlayerController->DisableInput(PlayerController);
    Player->SetGravityScale(0.0f);

    FTimerHandle UnusedHandle;
    GetWorldTimerManager().SetTimer(
        UnusedHandle, this, &AFPLevelBase::TimerElapsed, 3.0f, false);


    Super::BeginPlay();
}

void AFPLevelBase::Tick(float DeltaTime)
{
}

AFPPlayer* AFPLevelBase::GetPlayerFromGameMode()
{
    AGameModeBase* GameMode = UGameplayStatics::GetGameMode(this);
    if (AFPGameMode* MyGameMode = Cast<AFPGameMode>(GameMode))
    {
        UE_LOG(LogTemp, Log, TEXT("GetGameMode"));
        return MyGameMode->GetSpawnedPlayer();
    }
    return nullptr;
}

void AFPLevelBase::SetMappingContext()
{
    PlayerController = Cast<AFPPlayerController>(UGameplayStatics::GetPlayerController(this, 0));
    PlayerController->ChangeMappingContextQuaterJump();
}

void AFPLevelBase::SpawnCamera()
{
    FVector CameraLocation = FVector(0.0f, 0.0f, 1500.f);
    FRotator CameraRotation = FRotator(-40.0f, 0.0f, 0.0f);

    FTransform Transform(FRotator{ -40.0f, 0.0f, 0.0f }, FVector{ 0.0f, 300.0f, 1500.0f }, FVector{ 1.0f, 1.0f, 1.0f });
    
    if (Camera = GetWorld()->SpawnActor<ACameraActor>())
    {
        Camera->SetActorTransform(Transform);
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("No Camera"));
    }
}

void AFPLevelBase::StartFadeIn()
{
    PlayerController->ClientSetCameraFade(true, FColor::Black, FVector2D(3.0f,0.0f), 3.0f, false, true);
}

void AFPLevelBase::TimerElapsed()
{
    PlayerController->EnableInput(PlayerController);
}
