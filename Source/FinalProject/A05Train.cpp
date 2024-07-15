// Fill out your copyright notice in the Description page of Project Settings.


#include "A05Train.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AA05Train::AA05Train()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
	RootComponent = Body;
	Body->SetRelativeScale3D(FVector(2, 3, 0.5f));

	Wing = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Wing"));
	Wing->SetupAttachment(Body);
	Wing->SetRelativeLocationAndRotation(FVector(55, -72, 80), FRotator(0, 90, 0));
	Wing->SetRelativeScale3D(FVector(3.75f, 0.25f, 0.5f));

	Head = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Head"));
	Head->SetupAttachment(Body);
	Head->SetRelativeLocationAndRotation(FVector(105, 36, 40), FRotator(0, 0, 0));
	Head->SetRelativeScale3D(FVector(0.25f, 0.25f, 0.25f));

	Wing->SetRelativeLocation(FVector(0, 0, 0));
	Head->SetRelativeLocation(FVector(0, 0, 0));

	ConstructorHelpers::FObjectFinder<UStaticMesh> FindMesh(TEXT("/Script/Engine.StaticMesh'/Game/LevelDesign/LevelPrototyping/Meshes/SM_ChamferCube.SM_ChamferCube'"));
	if (FindMesh.Succeeded())
	{
		Body->SetStaticMesh(FindMesh.Object);
		Wing->SetStaticMesh(FindMesh.Object);
		Head->SetStaticMesh(FindMesh.Object);
	}
}

// Called when the game starts or when spawned
void AA05Train::BeginPlay()
{
	Super::BeginPlay();
	
	//Target = UGameplayStatics::GetActorOfClass(GetWorld(), AA05Train::StaticClass());
	TArray<AActor*> Actors;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), TEXT("Target"), Actors);

	if (Actors.Num())
	{
		Target = Actors[0];
	}
}

// Called every frame
void AA05Train::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Target != nullptr)
	{
		float Speed = 50.0f;
		float Distance = DeltaTime * Speed;

		FVector Location = GetActorLocation();

		FVector DirectionVector = Target->GetActorLocation() - GetActorLocation();
		DirectionVector.Normalize();

		AddActorWorldOffset(DirectionVector * Distance);
	}
}

