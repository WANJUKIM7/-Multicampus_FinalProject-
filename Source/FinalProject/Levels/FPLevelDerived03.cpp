// Fill out your copyright notice in the Description page of Project Settings.


#include "Levels/FPLevelDerived03.h"
#include "Actors/FP03Platform.h"

AFPLevelDerived03::AFPLevelDerived03()
	: Super()
	, TimePlatformsBreakLoop(3.0f)
{
}

void AFPLevelDerived03::BeginPlay()
{
	SetMappingContext();
	Super::BeginPlay();

	/*FTimerHandle BreakPlatformsHandle;

    GetWorldTimerManager().SetTimer(
        BreakPlatformsHandle, this, &AFPLevelDerived03::BreakPlatforms, TimePlatformsBreakLoop, true);*/
}

void AFPLevelDerived03::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AFPLevelDerived03::SetMappingContext()
{
	PlayerController = Cast<AFPPlayerController>(UGameplayStatics::GetPlayerController(this, 0));
    PlayerController->ChangeMappingContextThirdPersonDoubleJumpInteraction();
    PlayerController->DisableInput(PlayerController);
}

void AFPLevelDerived03::SpawnCamera()
{
}

void AFPLevelDerived03::BreakPlatforms()
{
	//TArray<AActor*> FoundPlatforms;
	//UGameplayStatics::GetAllActorsOfClass(GetWorld(), AFP03Platform::StaticClass(), FoundPlatforms);
	//for (AActor* Actor : FoundPlatforms)
 //   {
 //       //AFP03Platform* Platform = Cast<AFP03Platform>(Actor);
	//	UClass* ActorClass = Actor->GetClass();
	//	if (ActorClass->IsChildOf(AFP03Platform::StaticClass()))
	//	{
	//		TSubclassOf<AFP03Platform> PlatformClass = Cast<TSubclassOf<AFP03Platform>>(ActorClass);
	//		Platforms.Add(PlatformClass);
	//	}
 //       if (Platform->GetIsTimePassed())
 //       {
	//		Platforms.Add(Platform);
 //       }
	//	else
	//	{
	//		UE_LOG(LogTemp, Warning, TEXT("No Platforms Found"));
	//	}
 //   }

	//if (Platforms.Num() >= 1)
	//{
	//	int32 Index = FMath::RandRange(0, Platforms.Num());
	//	Platforms[Index].Get()->ShakeAndDestroy();
	//	Platforms.Empty();
	//}
}
