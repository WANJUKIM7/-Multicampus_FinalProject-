// Fill out your copyright notice in the Description page of Project Settings.


#include "Levels/FPLevelDerived02.h"
#include "Engine/DirectionalLight.h"
#include "Actors/FP02Spotlight.h"

AFPLevelDerived02::AFPLevelDerived02()
{
	ConstructorHelpers::FClassFinder<AFP02Spotlight> FindClass(TEXT("/Script/Engine.Blueprint'/Game/Programming/Blueprints/BP_02_SpotLight.BP_02_SpotLight_C'"));
	if (FindClass.Succeeded())
	{
		ActorClass = FindClass.Class;
	}
}

void AFPLevelDerived02::BeginPlay()
{
	SetMappingContext();
	SetSpawnValues();
	Super::BeginPlay();

	//if (Player)
	//{
	//	Player->SetCurrentLevel(ECurrentLevel::E_Level02);
	//}
	//else
	//{
	//	FP_LOG(LogFP, Warning, TEXT("%s"), TEXT("No Player"));
	//}

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

void AFPLevelDerived02::SetSpawnValues()
{
	LevelDatas->LevelBase.CameraSpawnLocation = LevelDatas->Level02.CameraSpawnLocation;
	LevelDatas->LevelBase.CameraSpawnRotation = LevelDatas->Level02.CameraSpawnRotation;
	LevelDatas->LevelBase.PlayerSpawnLocation = LevelDatas->Level02.PlayerSpawnLocation;
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
	/*FVector Location(-1000.0f, -1000.0f, -1000.0f);
	FRotator Rotation(0.0f, 0.0f, 0.0f);*/
	//AFP02Spotlight* Light = GetWorld()->SpawnActor<AFP02Spotlight>(Location, Rotation);
	AFP02Spotlight* Light = Cast<AFP02Spotlight>(GetWorld()->SpawnActor(ActorClass));
	Light->SetValues(LevelDatas->Level02.SpotLightCenterLocation, LevelDatas->Level02.MaxXOffset, LevelDatas->Level02.MaxYOffset);
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

    /*GetWorldTimerManager().SetTimer(
        SpawnPlayerHPUIHandle, Player.Get(), &AFPPlayer::SpawnPlayerHPUI, LevelDatas->LevelBase.TimeGameStarts, false);*/
	
	/*GetWorldTimerManager().SetTimer(
        DarkChangeHandle, this, &AFPLevelDerived02::DarkChange, TimeGameStarts, false);*/

	GetWorldTimerManager().SetTimer(
        SpawnSpotLightHandle, this, &AFPLevelDerived02::SpawnSpotLight, 0.5f, true, LevelDatas->LevelBase.TimeGameStarts);

	GetWorldTimerManager().SetTimer(
        Phase2SpawnTimeSpotLightHandle, this, &AFPLevelDerived02::Phase2SpawnTimeSpotLight, LevelDatas->LevelBase.TimeGameStarts + 6.0f, false);

	GetWorldTimerManager().SetTimer(
        Phase3SpawnTimeSpotLightHandle, this, &AFPLevelDerived02::Phase3SpawnTimeSpotLight, LevelDatas->LevelBase.TimeGameStarts + 12.0f, false);

}
