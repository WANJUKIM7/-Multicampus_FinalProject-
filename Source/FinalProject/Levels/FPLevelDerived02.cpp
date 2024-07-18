// Fill out your copyright notice in the Description page of Project Settings.


#include "Levels/FPLevelDerived02.h"
#include "Components/WidgetComponent.h"
#include "UI/FPPlayerHPWidget.h"
#include "Engine/DirectionalLight.h"
#include "Actors/FP02Spotlight.h"

AFPLevelDerived02::AFPLevelDerived02()
	: Super()
	, PlayerHP(nullptr)
	, SpotLightCenterLocation(FVector(1000.0f, 1000.0f, 320.0f))
{
	// Countdown Widget
    ConstructorHelpers::FClassFinder<UUserWidget> PlayerHPWidgetClass(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/Programming/UI/WB_PlayerHP.WB_PlayerHP_C'"));
    if (PlayerHPWidgetClass.Succeeded())
	{
		UE_LOG(LogTemp, Log, TEXT("PlayerHPWidgetClass.Succeeded"));
        PlayerHPWidgetClassReference = PlayerHPWidgetClass.Class;
	}
}

void AFPLevelDerived02::BeginPlay()
{
	SetMappingContext();
	Super::BeginPlay();

	SetTimer();
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

void AFPLevelDerived02::SpawnPlayerHPUI()
{
	PlayerHP = NewObject<UWidgetComponent>(this, UWidgetComponent::StaticClass());
    PlayerHP->SetWidgetClass(PlayerHPWidgetClassReference);
    PlayerHP->RegisterComponent();

    if (UFPPlayerHPWidget* UI = Cast<UFPPlayerHPWidget>(PlayerHP->GetUserWidgetObject()))
	{
        UI->AddToViewport();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerHP UI Failed"));
	}
}

void AFPLevelDerived02::DarkChange()
{
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ADirectionalLight::StaticClass(), FoundActors);
	for (AActor* Actor : FoundActors)
    {
        ADirectionalLight* DirLight = Cast<ADirectionalLight>(Actor);
        if (DirLight)
        {
			DirLight->SetBrightness(0.0f);			
        }
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("No Directional Light Found"));
		}
    }
}

void AFPLevelDerived02::SpawnSpotLight()
{
	AFP02Spotlight* Light = GetWorld()->SpawnActor<AFP02Spotlight>();
	Light->SetValues(SpotLightCenterLocation);
	//UE_LOG(LogTemp, Log, TEXT("SpawnSpotLight"));
}

void AFPLevelDerived02::Phase2SpawnTimeSpotLight()
{
	if (GetWorldTimerManager().IsTimerActive(SpawnSpotLightHandle))
    {
        GetWorldTimerManager().ClearTimer(SpawnSpotLightHandle);
        GetWorldTimerManager().SetTimer(
            SpawnSpotLightHandle, this, &AFPLevelDerived02::SpawnSpotLight, 0.3f, true);
		UE_LOG(LogTemp, Log, TEXT("Phase2SpawnTimeSpotLight"));
    }
}

void AFPLevelDerived02::Phase3SpawnTimeSpotLight()
{
	if (GetWorldTimerManager().IsTimerActive(SpawnSpotLightHandle))
    {
        GetWorldTimerManager().ClearTimer(SpawnSpotLightHandle);
        GetWorldTimerManager().SetTimer(
            SpawnSpotLightHandle, this, &AFPLevelDerived02::SpawnSpotLight, 0.1f, true);
		UE_LOG(LogTemp, Log, TEXT("Phase3SpawnTimeSpotLight"));
    }
}

void AFPLevelDerived02::SetTimer()
{
	UE_LOG(LogTemp, Log, TEXT("AFPLevelDerived02::SetTimer"));
	FTimerHandle SpawnPlayerHPUIHandle;
	FTimerHandle DarkChangeHandle;
	FTimerHandle Phase2SpawnTimeSpotLightHandle;
	FTimerHandle Phase3SpawnTimeSpotLightHandle;

    GetWorldTimerManager().SetTimer(
        SpawnPlayerHPUIHandle, this, &AFPLevelDerived02::SpawnPlayerHPUI, TimeGameStarts, false);
	
	GetWorldTimerManager().SetTimer(
        DarkChangeHandle, this, &AFPLevelDerived02::DarkChange, TimeGameStarts, false);

	GetWorldTimerManager().SetTimer(
        SpawnSpotLightHandle, this, &AFPLevelDerived02::SpawnSpotLight, 0.5f, true, TimeGameStarts);

	GetWorldTimerManager().SetTimer(
        Phase2SpawnTimeSpotLightHandle, this, &AFPLevelDerived02::Phase2SpawnTimeSpotLight, TimeGameStarts + 6.0f, false);

	GetWorldTimerManager().SetTimer(
        Phase3SpawnTimeSpotLightHandle, this, &AFPLevelDerived02::Phase3SpawnTimeSpotLight, TimeGameStarts + 12.0f, false);

}
