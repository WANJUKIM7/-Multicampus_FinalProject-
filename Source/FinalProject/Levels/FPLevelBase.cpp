// Fill out your copyright notice in the Description page of Project Settings.


#include "Levels/FPLevelBase.h"
#include "GameMode/FPGameMode.h"
#include "Camera/CameraActor.h"
#include "Components/WidgetComponent.h"
#include "UI/FPStartCountdownWidget.h"
#include "Actors/FPPortalEnterLevel.h"

AFPLevelBase::AFPLevelBase()
{
    // Countdown Widget
    ConstructorHelpers::FClassFinder<UUserWidget> CountdownWidgetClass(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/Programming/UI/WB_Countdown.WB_Countdown_C'"));
    if (CountdownWidgetClass.Succeeded())
	{
		UE_LOG(LogTemp, Log, TEXT("CountdownWidgetClass.Succeeded"));
        CountdownWidgetClassReference = CountdownWidgetClass.Class;
	}

    // Level Datas
    static ConstructorHelpers::FObjectFinder<UFPLevelDatas> DataAsset(TEXT("/Script/FinalProject.FPLevelDatas'/Game/Programming/Data/DA_LevelDatas.DA_LevelDatas'"));
    if (DataAsset.Succeeded())
    {
        LevelDatas = DataAsset.Object;
        UE_LOG(LogTemp, Log, TEXT("DataAsset.Succeeded()"));
        
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("DataAsset failed()"));
    }

    //LevelDatas->LevelBase.CameraSpawnLocation = FVector(-700.0f, 780.0f, 1000.0f);
}

void AFPLevelBase::BeginPlay()
{
    //StartFadeIn();
    SetSpawnValues();
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

void AFPLevelBase::InitializeLevelSettings()
{
}

AFPPlayer* AFPLevelBase::GetPlayerFromGameMode()
{
    if (HasAuthority())
    {
        AGameModeBase* GameMode = UGameplayStatics::GetGameMode(this);
        if (AFPGameMode* MyGameMode = Cast<AFPGameMode>(GameMode))
        {
            //return MyGameMode->GetSpawnedPlayer();
        }
    }
    else
    {
        APlayerController* NewPlayerController = UGameplayStatics::GetPlayerController(this, 0);
        if (NewPlayerController)
        {
            AFPPlayer* NewPlayer = Cast<AFPPlayer>(NewPlayerController->GetPawn());
            return NewPlayer;
        }
    }
    return nullptr;
}

void AFPLevelBase::StartFadeIn()
{
    PlayerController->ClientSetCameraFade(true, FColor::Black, FVector2D(3.0f, 0.0f), 3.0f, false, true);
}

void AFPLevelBase::PlayerSetting()
{
    //Player = GetPlayerFromGameMode();
    /*if (Player)
    {
        Player->SetActorLocation(LevelDatas->LevelBase.PlayerSpawnLocation);
        Player->SetActorRotation(FRotator(0.0f, 0.0f, 0.0f));
        Player->SetGravityScale(0.0f);
        Player->SetMovementReset();
        Player->SetActorHiddenInGame(true);
        UE_LOG(LogTemp, Log, TEXT("Player obtained from GameMode: %s"), *Player->GetName());
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Player doesn't get"));
    }*/
}

void AFPLevelBase::SetMappingContext()
{
    PlayerController = Cast<AFPPlayerController>(UGameplayStatics::GetPlayerController(this, 0));
    PlayerController->ChangeMappingContextQuater();
    PlayerController->DisableInput(PlayerController);
}

void AFPLevelBase::SpawnCamera()
{
    FTransform Transform(LevelDatas->LevelBase.CameraSpawnRotation, LevelDatas->LevelBase.CameraSpawnLocation, FVector{ 1.0f, 1.0f, 1.0f });
    
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

void AFPLevelBase::SetSpawnValues()
{
}

void AFPLevelBase::SetTimer()
{
    UE_LOG(LogTemp, Log, TEXT("AFPLevelBase::SetTimer"));
    FTimerHandle PortalHandle;
    FTimerHandle CountdownStartHandle;
    FTimerHandle GameStartHandle;
    FTimerHandle PlayerControlable;

    GetWorldTimerManager().SetTimer(
        PortalHandle, this, &AFPLevelBase::SpawnPortal, LevelDatas->LevelBase.TimeSpawnPortal, false);

    GetWorldTimerManager().SetTimer(
        GameStartHandle, this, &AFPLevelBase::SpawnPlayer, LevelDatas->LevelBase.TimeSpawnPlayer, false);

    GetWorldTimerManager().SetTimer(
        CountdownStartHandle, this, &AFPLevelBase::StartCountdown, LevelDatas->LevelBase.TimeCountDownStarts, false);

    GetWorldTimerManager().SetTimer(
        PlayerControlable, this, &AFPLevelBase::PlayerControlable, 1.0f, false);
}

void AFPLevelBase::SpawnPortal()
{
    /*AFPPortalEnterLevel* Particle = GetWorld()->SpawnActor<AFPPortalEnterLevel>(Player->GetActorLocation(), FRotator(0.0f, 0.0f, 0.0f));*/
}

void AFPLevelBase::SpawnPlayer()
{
    UE_LOG(LogTemp, Log, TEXT("SpawnPlayer"));
    /*if (Player)
    {
        Player->SetGravityScale(1.75f);
        Player->SetActorHiddenInGame(false);
    }*/
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
        Countdown->GetUserWidgetObject()->RemoveFromParent();
        Countdown->DestroyComponent();
        UE_LOG(LogTemp, Log, TEXT("Countdown widget destroyed"));
    }
}

void AFPLevelBase::PlayerControlable()
{
    UE_LOG(LogTemp, Log, TEXT("PlayerControlable"));
    PlayerController->EnableInput(PlayerController);
}

void AFPLevelBase::CheckGameState()
{
    if (AGameStateBase* GameState = UGameplayStatics::GetGameState(this))
	{
		AFPGameState* FPGameState = Cast<AFPGameState>(GameState);
		if (FPGameState && FPGameState->IsGameOver())
		{
			// Handle game over logic here
			UE_LOG(LogTemp, Log, TEXT("Game Over!"));
		}
	}
}
