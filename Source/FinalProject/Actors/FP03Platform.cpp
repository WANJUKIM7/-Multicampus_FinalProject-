// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/FP03Platform.h"
#include "Components/BoxComponent.h"
#include "Components/TimelineComponent.h"
#include "TimerManager.h"
#include "Curves/CurveFloat.h"
#include "System/FPAssetManager.h"
#include "Data/FPLevelAssets.h"

// Sets default values
AFP03Platform::AFP03Platform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootScene = CreateDefaultSubobject<USceneComponent>(TEXT("RootScene"));
	RootComponent = RootScene;

	Platform = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Platform"));
	Platform->SetupAttachment(RootScene);
	Platform->SetRelativeScale3D(FVector(1.0f, 1.0f, 0.1f));
	Platform->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	Platform->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	BoxCollision->SetupAttachment(Platform);
	BoxCollision->SetCollisionProfileName(TEXT("OverlapAll"));
	BoxCollision->SetRelativeLocation(FVector(0.0f, -0.014286, -0.130185));
	BoxCollision->SetRelativeScale3D(FVector(0.0024f, 0.0002f, 0.00405f));
	BoxCollision->SetHiddenInGame(false);
	
	BoxCollision1 = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision1"));
	BoxCollision1->SetupAttachment(Platform);
	BoxCollision1->SetCollisionProfileName(TEXT("OverlapAll"));
	BoxCollision1->SetRelativeLocation(FVector(0.0f, -0.014286f, -0.130185f));
	BoxCollision1->SetRelativeRotation(FRotator(60.0f, 0.0f, 0.0f));
	BoxCollision1->SetRelativeScale3D(FVector(0.0024f, 0.0002f, 0.00405f));
	BoxCollision1->SetHiddenInGame(false);

	BoxCollision2 = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision2"));
	BoxCollision2->SetupAttachment(Platform);
	BoxCollision2->SetCollisionProfileName(TEXT("OverlapAll"));
	BoxCollision2->SetRelativeLocation(FVector(0.0f, -0.014286f, -0.130185f));
	BoxCollision2->SetRelativeRotation(FRotator(120.0f, 0.0f, 0.0f));
	BoxCollision2->SetRelativeScale3D(FVector(0.0024f, 0.0002f, 0.00405f));
	BoxCollision2->SetHiddenInGame(false);

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
	if (const UFPLevelAssets* LevelData = UFPAssetManager::GetAssetByName<UFPLevelAssets>("LevelAsset"))
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
			Platform->SetMaterial(0, LevelData->Level03Assets[0].PlatformMaterialInstance);
		}

	}

	// Shake
	OriginalLocation = Platform->GetComponentLocation();

	// Bind Collision
	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnBeginOverlap);
	BoxCollision1->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnBeginOverlap);
	BoxCollision2->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnBeginOverlap);

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

