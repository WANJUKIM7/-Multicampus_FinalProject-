// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/FP01Bomb.h"

// Sets default values
AFP01Bomb::AFP01Bomb()
	: Super()
	, IsInteracting(false)
	, TimeExplode(10.0f)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Bomb = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Bomb"));
	RootComponent = Bomb;
	Bomb->SetRelativeScale3D(FVector(0.3f, 0.3f, 0.3f));

	ConstructorHelpers::FObjectFinder<UStaticMesh> FindMesh(TEXT("/Script/Engine.StaticMesh'/Game/LevelDesign/LevelPrototyping/Meshes/SM_ChamferCube.SM_ChamferCube'"));
	if (FindMesh.Succeeded())
	{
		Bomb->SetStaticMesh(FindMesh.Object);
	}
	Bomb->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	Bomb->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
}

// Called when the game starts or when spawned
void AFP01Bomb::BeginPlay()
{
	Super::BeginPlay();
	
	Bomb->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnBeginOverlap);
	
}

// Called every frame
void AFP01Bomb::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TimeExplode -= DeltaTime;
	if (TimeExplode <= 0.0f)
	{
		SetActorTickEnabled(false);
		Destroy();
		//GetAttachParentActor()->Destroy();
		UE_LOG(LogTemp, Log, TEXT("Bomb Exploded!"));
	}
}

void AFP01Bomb::ResetTimer()
{
	TimeExplode = 10.0f;
}

void AFP01Bomb::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (!IsInteracting)
		return;

	UE_LOG(LogTemp, Log, TEXT("Bomb Begin Overlap1: %s"), *GetAttachParentActor()->GetName());
	UE_LOG(LogTemp, Log, TEXT("Bomb Begin Overlap2: %s"), *GetAttachParentActor()->GetName());

	if (GetAttachParentActor()->GetName() != OtherActor->GetName())
		return;

	UE_LOG(LogTemp, Log, TEXT("Bomb Begin Overlap!"));

	//Cast<FPPlayer>(OtherActor)
}

//void AFP01Bomb::AttachBombToComponent(USceneComponent* ParentComponent)
//{
//	if (Bomb && ParentComponent)
//    {
//        Bomb->AttachToComponent(ParentComponent, FAttachmentTransformRules::KeepRelativeTransform);
//        UE_LOG(LogTemp, Log, TEXT("Bomb attached to component: %s"), *ParentComponent->GetName());
//    }
//    else
//    {
//        UE_LOG(LogTemp, Warning, TEXT("Failed to attach bomb. Either Bomb or ParentComponent is null."));
//    }
//}

