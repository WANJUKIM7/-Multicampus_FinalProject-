// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/FP01Bomb.h"
#include "Character/FPPlayer.h"
#include "FP01BombParticle.h"

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
	Bomb->SetRelativeScale3D(FVector(1.0f, 1.0f, 1.0f));

	ConstructorHelpers::FObjectFinder<UStaticMesh> FindMesh(TEXT("/Script/Engine.StaticMesh'/Game/contents/TnT/TNT_FBX.TNT_FBX'"));
	if (FindMesh.Succeeded())
	{
		Bomb->SetStaticMesh(FindMesh.Object);
	}
	Bomb->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	Bomb->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	ConstructorHelpers::FObjectFinder<UMaterial> FindMaterial(TEXT("/Script/Engine.Material'/Game/contents/TnT/Diffuse_map_Mat.Diffuse_map_Mat'"));
    if (FindMaterial.Succeeded())
    {
        Bomb->SetMaterial(0, FindMaterial.Object);
    }
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
		AFP01BombParticle* Particle = GetWorld()->SpawnActor<AFP01BombParticle>(GetActorLocation(), FRotator(0.0f, 0.0f, 0.0f));
		if (GetAttachParentActor())
		{
			Cast<AFPPlayer>(GetAttachParentActor())->DestroyPlayer();
		}
		Destroy();
		UE_LOG(LogTemp, Log, TEXT("Bomb Exploded!"));
	}
}

void AFP01Bomb::ResetTimer()
{
	TimeExplode = 10.0f;
}

void AFP01Bomb::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	/*if (!IsInteracting)
		return;*/

	/*UE_LOG(LogTemp, Log, TEXT("Bomb Begin Overlap1: %s"), *GetAttachParentActor()->GetName());
	UE_LOG(LogTemp, Log, TEXT("Bomb Begin Overlap2: %s"), *OtherActor->GetName());*/

	if (GetAttachParentActor()->GetName() == OtherActor->GetName())
		return;

	if (AFPPlayer* NewPlayer = Cast<AFPPlayer>(OtherActor))
	{
		if (Cast<AFPPlayer>(GetAttachParentActor())->GetIsInteracting() == false)
			return;
		Cast<AFPPlayer>(GetAttachParentActor())->SetIsAttachedBomb(false);
		AttachToComponent(NewPlayer->GetMesh(),FAttachmentTransformRules::KeepRelativeTransform, FName("bomb"));
		NewPlayer->SetIsAttachedBomb(true);
		ResetTimer();
		UE_LOG(LogTemp, Log, TEXT("Bomb Begin Overlap!"));
	}
}
