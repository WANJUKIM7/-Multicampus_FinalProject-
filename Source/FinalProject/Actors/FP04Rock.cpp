// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/FP04Rock.h"
#include "Components/SphereComponent.h"

// Sets default values
AFP04Rock::AFP04Rock()
	: SizeSmall(FVector(0.3f, 0.3f, 0.3f))
	, SizeMiddle(FVector(0.5f, 0.5f, 0.5f))
	, SizeLarge(FVector(1.0f, 1.0f, 1.0f))
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Rock = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Rock"));
	RootComponent = Rock;
	Rock->SetSimulatePhysics(true);

	ConstructorHelpers::FObjectFinder<UStaticMesh> FindMesh(TEXT("/Script/Engine.StaticMesh'/Game/Content/StarterContent/Props/MaterialSphere.MaterialSphere'"));
	if (FindMesh.Succeeded())
	{
		Rock->SetStaticMesh(FindMesh.Object);
	}
	Rock->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);
	//Rock->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);

	SphereCollision = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollision"));
	SphereCollision->SetupAttachment(Rock);
	SphereCollision->InitSphereRadius(160.0f);
	SphereCollision->SetCollisionProfileName(TEXT("OverlapAll"));
	SphereCollision->SetHiddenInGame(false);
}

// Called when the game starts or when spawned
void AFP04Rock::BeginPlay()
{
	Super::BeginPlay();
	
	SetLifeSpan(10.0f);

	int32 RandomInteger = FMath::RandRange(0, 2);
	switch (RandomInteger)
	{
	case 0:
		Rock->SetRelativeScale3D(SizeSmall);
		break;
	case 1:
		Rock->SetRelativeScale3D(SizeMiddle);
		break;
	case 2:
		Rock->SetRelativeScale3D(SizeLarge);
		break;
	default:
		break;
	};

	SphereCollision->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnBeginOverlap);
}

// Called every frame
void AFP04Rock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFP04Rock::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	
}

