// Fill out your copyright notice in the Description page of Project Settings.


#include "Levels/FPLevelBase.h"
#include "Character/FPPlayer.h"
#include "GameMode/FPGameMode.h"
#include "Camera/CameraActor.h"
#include "Components/WidgetComponent.h"
#include "UI/FPStartCountdownWidget.h"

AFPLevelBase::AFPLevelBase()
	: Player(nullptr)
    , Camera(nullptr)
    , PlayerController(nullptr)
    , Countdown(nullptr)
    , TimeSpawnPlayer(1.0f)
    , TimeCountDownStarts(3.0f)
    , TimeGameStarts(8.0f)
{
    // Countdown Widget
    ConstructorHelpers::FClassFinder<UUserWidget> CountdownWidgetClass(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/Programming/UI/WB_Countdown.WB_Countdown_C'"));
    if (CountdownWidgetClass.Succeeded())
	{
		UE_LOG(LogTemp, Log, TEXT("CountdownWidgetClass.Succeeded"));
        CountdownWidgetClassReference = CountdownWidgetClass.Class;
	}
}

void AFPLevelBase::BeginPlay()
{
    //StartFadeIn();
    PlayerSetting();
    //SetMappingContext();
    SpawnCamera();
    SetTimer();
    
    Super::BeginPlay();
}

void AFPLevelBase::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
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

void AFPLevelBase::StartFadeIn()
{
    PlayerController->ClientSetCameraFade(true, FColor::Black, FVector2D(3.0f, 0.0f), 3.0f, false, true);
}

void AFPLevelBase::PlayerSetting()
{
    Player = GetPlayerFromGameMode();
    if (Player)
    {
        Player->GetController();
        Player->SetActorLocation(FVector(1000.0f, 500.0f, 500.0f));
        Player->SetGravityScale(0.0f);
        Player->SetActorHiddenInGame(true);
        UE_LOG(LogTemp, Log, TEXT("Player obtained from GameMode: %s"), *Player->GetName());
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Player doesn't get"));
    }
}

void AFPLevelBase::SetMappingContext()
{
    PlayerController = Cast<AFPPlayerController>(UGameplayStatics::GetPlayerController(this, 0));
    PlayerController->ChangeMappingContextQuater();
    PlayerController->DisableInput(PlayerController);
}

void AFPLevelBase::SpawnCamera()
{
    FTransform Transform(FRotator{ -40.0f, 0.0f, 0.0f }, FVector{ 0.0f, 300.0f, 1500.0f }, FVector{ 1.0f, 1.0f, 1.0f });
    
    if (Camera = GetWorld()->SpawnActor<ACameraActor>())
    {
        Camera->SetActorTransform(Transform);
        UE_LOG(LogTemp, Log, TEXT("Camera Spawn Succeeded"));
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("No Camera"));
    }
}

void AFPLevelBase::SetTimer()
{
    FTimerHandle CountdownStartHandle;
    FTimerHandle GameStartHandle;
    FTimerHandle PlayerControlable;

    GetWorldTimerManager().SetTimer(
        GameStartHandle, this, &AFPLevelBase::SpawnPlayer, TimeSpawnPlayer, false);

    GetWorldTimerManager().SetTimer(
        CountdownStartHandle, this, &AFPLevelBase::StartCountdown, TimeCountDownStarts, false);

    GetWorldTimerManager().SetTimer(
        PlayerControlable, this, &AFPLevelBase::PlayerControlable, TimeGameStarts, false);
}

void AFPLevelBase::SpawnPlayer()
{
    UE_LOG(LogTemp, Log, TEXT("SpawnPlayer"));
    Player->SetGravityScale(1.75f);
    Player->SetActorHiddenInGame(false);
}

void AFPLevelBase::StartCountdown()
{
    Countdown = NewObject<UWidgetComponent>(this, UWidgetComponent::StaticClass());
    Countdown->SetWidgetClass(CountdownWidgetClassReference);
    Countdown->RegisterComponent();

    if (UFPStartCountdownWidget* UI = Cast<UFPStartCountdownWidget>(Countdown->GetUserWidgetObject()))
	{
        UI->AddToViewport();
        FTimerHandle DestroyCountdownHandle;
        GetWorldTimerManager().SetTimer(
            DestroyCountdownHandle, this, &AFPLevelBase::DestroyCountdownWidget, 3.0f, false);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Countdown UI Failed"));
	}
}

void AFPLevelBase::DestroyCountdownWidget()
{
    if (Countdown && Countdown->GetUserWidgetObject())
    {
        Countdown->GetUserWidgetObject()->RemoveFromViewport();
        Countdown->DestroyComponent();
        UE_LOG(LogTemp, Log, TEXT("Countdown widget destroyed"));
    }
}

void AFPLevelBase::PlayerControlable()
{
    UE_LOG(LogTemp, Log, TEXT("PlayerControlable"));
    PlayerController->EnableInput(PlayerController);
}
