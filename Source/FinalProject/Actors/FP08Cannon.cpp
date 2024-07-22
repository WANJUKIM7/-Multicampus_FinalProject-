// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/FP08Cannon.h"
#include "Components/ArrowComponent.h"

// Sets default values
AFP08Cannon::AFP08Cannon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Cannon = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cannon"));
	RootComponent = Cannon;

	ConstructorHelpers::FObjectFinder<UStaticMesh> FindMesh(TEXT("/Script/Engine.StaticMesh'/Game/contents/VFX/Sci-Fi_Starter_VFX_Pack_Niagara/Mesh/SM_Sphere_2.SM_Sphere_2'"));
	if (FindMesh.Succeeded())
	{
		Cannon->SetStaticMesh(FindMesh.Object);
	}

	ArrowMiddle = CreateDefaultSubobject<UArrowComponent>(TEXT("ArrowMiddle"));
    ArrowMiddle->SetupAttachment(Cannon);
    ArrowMiddle->SetArrowColor(FColor::Red);
    ArrowMiddle->SetArrowSize(1.0f);
	ArrowMiddle->SetArrowLength(80.0f);
	ArrowMiddle->SetRelativeLocation(FVector(0.0f, 0.0f, 130.0f));
	ArrowMiddle->SetRelativeRotation(FRotator(0.0f, 90.0f, 0.0f));

	ArrowLeft = CreateDefaultSubobject<UArrowComponent>(TEXT("ArrowLeft"));
    ArrowLeft->SetupAttachment(Cannon);
    ArrowLeft->SetArrowColor(FColor::Red);
    ArrowLeft->SetArrowSize(1.0f);
	ArrowLeft->SetArrowLength(80.0f);
	ArrowLeft->SetRelativeLocation(FVector(0.0f, 0.0f, 130.0f));
	ArrowLeft->SetRelativeRotation(FRotator(180.0f, 45.0f, 180.0f));

	ArrowRight = CreateDefaultSubobject<UArrowComponent>(TEXT("ArrowRight"));
    ArrowRight->SetupAttachment(Cannon);
    ArrowRight->SetArrowColor(FColor::Red);
    ArrowRight->SetArrowSize(1.0f);
	ArrowRight->SetArrowLength(80.0f);
	ArrowRight->SetRelativeLocation(FVector(0.0f, 0.0f, 130.0f));
	ArrowRight->SetRelativeRotation(FRotator(0.0f, 45.0f, 0.0f));
}

// Called when the game starts or when spawned
void AFP08Cannon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFP08Cannon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

