// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/FP03Platform.h"
#include "Components/BoxComponent.h"
#include "Components/TimelineComponent.h"
#include "TimerManager.h"
#include "Curves/CurveFloat.h"
#include "System/FPAssetManager.h"
#include "Data/FPLevelData.h"

// Sets default values
AFP03Platform::AFP03Platform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Platform = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Platform"));
	RootComponent = Platform;
	Platform->SetRelativeScale3D(FVector(1.0f, 1.0f, 0.1f));
	Platform->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	Platform->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	BoxCollision->SetupAttachment(Platform);
	BoxCollision->SetCollisionProfileName(TEXT("OverlapAll"));
	BoxCollision->SetRelativeLocation(FVector(0.0f, 0.0f, 50.0f));
	BoxCollision->SetRelativeScale3D(FVector(1.5f, 1.5f, 1.0f));
	BoxCollision->SetHiddenInGame(false);

	// Change Material
	//static ConstructorHelpers::FObjectFinder<UMaterial> Material(TEXT("/Script/Engine.Material'/Game/Programming/Materials/MM_Bright.MM_Bright'"));
 //   if (Material.Succeeded())
 //   {
 //       //Platform->SetMaterial(0, Material.Object);
	//	DynamicObject = Material.Object;
	//	UE_LOG(LogTemp, Log, TEXT("Material.Succeeded()"));
 //   }

	//static ConstructorHelpers::FObjectFinder<UCurveFloat> Curve(TEXT("/Script/Engine.CurveFloat'/Game/Programming/FloatCurve.FloatCurve'"));
	//if (Curve.Succeeded())
	//{
	//	UE_LOG(LogTemp, Log, TEXT("Curve.Succeeded()"));
	//	FloatCurve = Curve.Object;
	//}
}

// Called when the game starts or when spawned
void AFP03Platform::BeginPlay()
{
	Super::BeginPlay();
	
	// Set Mesh, Material
	if (const UFPLevelData* LevelData = UFPAssetManager::GetAssetByName<UFPLevelData>("LevelData"))
	{
		if (LevelData->Level03Assets[0].Platform)
		{
			Platform->SetStaticMesh(LevelData->Level03Assets[0].Platform);
			UE_LOG(LogTemp, Log, TEXT("Platform Found!"));
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Platform Not Founded!"));
		}

		if (LevelData->Level03Assets[0].PlatformMaterial)
		{
			Platform->SetMaterial(0, LevelData->Level01Assets[0].BombMaterial);
		}

	}

	// Shake
	OriginalLocation = Platform->GetComponentLocation();

	// Bind Collision
	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnBeginOverlap);

	// Change Material
	FOnTimelineFloat TimelineCallback;
	FOnTimelineEvent TimelineFinishedCallback;

	/*TimelineCallback.BindUFunction(this, FName("ChangeMaterialTimeline"));
	TimelineFinishedCallback.BindUFunction(this, FName("ChangeMaterialFinished"));

	MaterialTimeline.AddInterpFloat(FloatCurve, TimelineCallback);
	MaterialTimeline.SetTimelineFinishedFunc(TimelineFinishedCallback);*/
}

// Called every frame
void AFP03Platform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (IsShaking)
	{
		ElapsedShakingTime += DeltaTime;
		ShakeMesh(DeltaTime);

		if (ElapsedShakingTime >= ShakingDuration)
		{
			IsShaking = false;
			Platform->SetWorldLocation(OriginalLocation);
		}
	}
	//MaterialTimeline.TickTimeline(DeltaTime);
}

void AFP03Platform::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//Durability--;
	UE_LOG(LogTemp, Log, TEXT("Durability : %d"), Durability);
	switch (Durability)
	{
	case 0:
		ShakeAndDestroy();
		break;
	case 1:
		ChangeMaterial();
		break;
	default:
		break;
	}
}

void AFP03Platform::ChangeMaterial()
{
	//Platform->SetMaterial(0, DynamicObject);
	// Ready to break
	FTimerHandle ReadyToRandomBreakHandle;
    GetWorldTimerManager().SetTimer(
        ReadyToRandomBreakHandle, this, &AFP03Platform::ReadyToRandomBreak, TimeAfterDuration, false);
}

void AFP03Platform::ChangeMaterialTimeline(float Value)
{
	//DynamicMaterialInstance->SetScalarParameterValue(FName("Opacity"), Value);
	//Platform->SetMaterial(0, DynamicMaterialInstance);
	//UE_LOG(LogTemp, Log, TEXT("ChangeMaterialTimeline"));
}

void AFP03Platform::ChangeMaterialFinished()
{
	UE_LOG(LogTemp, Log, TEXT("ChangeMaterialFinished"));
	Destroy();
}

void AFP03Platform::ShakeAndDestroy()
{
	IsTimePassed = false;
	IsShaking = true;
	//MaterialTimeline.PlayFromStart();
}

void AFP03Platform::ShakeMesh(float DeltaTime)
{
	if (IsShaking)
    {
        FVector ShakeOffset = FVector(
            FMath::FRandRange(-5.0f, 5.0f),
            FMath::FRandRange(-5.0f, 5.0f),
            FMath::FRandRange(-5.0f, 5.0f)
        );

        FVector NewLocation = OriginalLocation + ShakeOffset;
        Platform->SetWorldLocation(NewLocation);
    }
}

void AFP03Platform::ReadyToRandomBreak()
{
	IsTimePassed = true;
}

