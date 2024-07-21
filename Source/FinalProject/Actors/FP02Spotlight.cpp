// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/FP02Spotlight.h"
#include "Components/SpotLightComponent.h"
#include "Components/SphereComponent.h"
#include "Character/FPPlayer.h"

// Sets default values
AFP02Spotlight::AFP02Spotlight()
	: Player(nullptr)
	, PerDamage(5.0f)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	SpotLight = CreateDefaultSubobject<USpotLightComponent>(TEXT("SpotLight"));
	SpotLight->SetupAttachment(RootComponent);
	SpotLight->SetRelativeRotation(FRotator(-90.0f, 0.0f, 0.0f));
	SpotLight->SetIntensity(100000.0f);
	SpotLight->SetOuterConeAngle(22.0f);

	SphereCollision = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollision"));
	SphereCollision->SetupAttachment(SpotLight);
	SphereCollision->InitSphereRadius(120.0f);
	SphereCollision->SetCollisionProfileName(TEXT("OverlapAll"));
	SphereCollision->SetRelativeLocation(FVector(300.0f, 0.0f, 0.0f));
	SphereCollision->SetHiddenInGame(false);

	StartLocation = FVector(1301.0f, 1080.0f, 650.0f);
	EndLocation = FVector(1000.0f, 1000.0f, 1500.0f);
	RandomInteger = 0;
}

// Called when the game starts or when spawned
void AFP02Spotlight::BeginPlay()
{
	Super::BeginPlay();
	
	SetLifeSpan(10.0f);
	SetActorLocation(FVector(0.0f, 0.0f, 320.0f));

	SphereCollision->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnBeginOverlap);
	SphereCollision->OnComponentEndOverlap.AddDynamic(this, &ThisClass::OnEndOverlap);
}

// Called every frame
void AFP02Spotlight::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	SetActorLocation(FMath::VInterpTo(GetActorLocation(), EndLocation, 0.001f, 10.0f));
	if (Player)
	{
		float NewHP = 0.0f;
		NewHP = FMath::Clamp(Player->GetHP() - PerDamage, 0.0f, Player->GetHP() - PerDamage);
		Player->SetHP(NewHP);
		Player->UpdateHPUI(NewHP);
		//UE_LOG(LogTemp, Log, TEXT("AFP02Spotlight::Tick"));
	}
}

void AFP02Spotlight::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (Player = Cast<AFPPlayer>(OtherActor))
	{
		/*UE_LOG(LogTemp, Log, TEXT("AFP02Spotlight::OnBeginOverlap"));
		UE_LOG(LogTemp, Log, TEXT("OtherActor->Name: %s"), *OtherActor->GetClass()->GetName());*/
	}
	
	//Player->SetSpotLightCounts(Player->GetSpotLightCounts() + 1u);
}

void AFP02Spotlight::OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (Player = Cast<AFPPlayer>(OtherActor))
	{
		Player = nullptr;
		//UE_LOG(LogTemp, Log, TEXT("AFP02Spotlight::OnEndOverlap"));
	}
	//Player->SetSpotLightCounts(Player->GetSpotLightCounts() - 1u);
}

void AFP02Spotlight::SetValues(FVector SpawnLocation)
{
	StartLocation = SpawnLocation;
	EndLocation = SpawnLocation;
	SetStartLocation();
	SetEndLocation();
	/*UE_LOG(LogTemp, Log, TEXT("StartLocation.X: %f, StartLocation.Y: %f, StartLocation.Z: %f"),StartLocation.X, StartLocation.Y,StartLocation.Z);
	UE_LOG(LogTemp, Log, TEXT("EndLocation.X: %f, EndLocation.Y: %f, EndLocation.Z: %f"),EndLocation.X, EndLocation.Y,EndLocation.Z);*/
}

void AFP02Spotlight::SetStartLocation()
{
	RandomInteger = FMath::RandRange(0, 3);
	float MaxXOffset = 1000.0f;
	float MaxYOffset = 1000.0f;
	float RandomXOffset = FMath::RandRange(-MaxXOffset, MaxXOffset);
	float RandomYOffset = FMath::RandRange(-MaxYOffset, MaxYOffset);
	//UE_LOG(LogTemp, Log, TEXT("SetStartLocation"));
	//UE_LOG(LogTemp, Log, TEXT("RandomInteger: %d, MaxXOffset: %f, MaxYOffset: %f, RandomXOffset: %f, RandomYOffset: %f,"), RandomInteger, MaxXOffset, MaxYOffset, RandomXOffset, RandomYOffset);
	switch (RandomInteger)
	{
	case 0:
		StartLocation.X = StartLocation.X - MaxXOffset;
		StartLocation.Y = StartLocation.Y + RandomYOffset;
		StartLocation.Z = StartLocation.Z;
		//UE_LOG(LogTemp, Log, TEXT("Case 0"));
		break;
	case 1:
		StartLocation.X = StartLocation.X + MaxXOffset;
		StartLocation.Y = StartLocation.Y + RandomYOffset;
		StartLocation.Z = StartLocation.Z;
		//UE_LOG(LogTemp, Log, TEXT("Case 1"));
		break;
	case 2:
		StartLocation.X = StartLocation.X + RandomXOffset;
		StartLocation.Y = StartLocation.Y - MaxYOffset;
		StartLocation.Z = StartLocation.Z;
		//UE_LOG(LogTemp, Log, TEXT("Case 2"));
		break;
	case 3:
		StartLocation.X = StartLocation.X + RandomXOffset;
		StartLocation.Y = StartLocation.Y + MaxYOffset;
		StartLocation.Z = StartLocation.Z;
		//UE_LOG(LogTemp, Log, TEXT("Case 3"));
		break;
	default:
		//UE_LOG(LogTemp, Log, TEXT("Case default"));
		break;
	}
	SetActorLocation(StartLocation);
}

void AFP02Spotlight::SetEndLocation()
{
	float MaxXOffset = 1000.0f;
	float MaxYOffset = 1000.0f;
	float RandomXOffset = FMath::RandRange(-MaxXOffset, MaxXOffset);
	float RandomYOffset = FMath::RandRange(-MaxYOffset, MaxYOffset);
	/*UE_LOG(LogTemp, Log, TEXT("SetEndLocation"));
	UE_LOG(LogTemp, Log, TEXT("RandomInteger: %d, MaxXOffset: %f, MaxYOffset: %f, RandomXOffset: %f, RandomYOffset: %f,"), RandomInteger, MaxXOffset, MaxYOffset, RandomXOffset, RandomYOffset);*/
	switch (RandomInteger)
	{
	case 0:
		EndLocation.X = EndLocation.X + MaxXOffset;
		EndLocation.Y = EndLocation.Y + RandomYOffset;
		EndLocation.Z = EndLocation.Z;
		//UE_LOG(LogTemp, Log, TEXT("Case 00"));
		break;
	case 1:
		EndLocation.X = EndLocation.X - MaxXOffset;
		EndLocation.Y = EndLocation.Y + RandomYOffset;
		EndLocation.Z = EndLocation.Z;
		//UE_LOG(LogTemp, Log, TEXT("Case 11"));
		break;
	case 2:
		EndLocation.X = EndLocation.X + RandomXOffset;
		EndLocation.Y = EndLocation.Y + MaxYOffset;
		EndLocation.Z = EndLocation.Z;
		//UE_LOG(LogTemp, Log, TEXT("Case 22"));
		break;
	case 3:
		EndLocation.X = EndLocation.X + RandomXOffset;
		EndLocation.Y = EndLocation.Y - MaxYOffset;
		EndLocation.Z = EndLocation.Z;
		//UE_LOG(LogTemp, Log, TEXT("Case 33"));
		break;
	default:
		//UE_LOG(LogTemp, Log, TEXT("Case defaultdefault"));
		break;
	}
}

