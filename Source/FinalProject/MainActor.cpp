// Fill out your copyright notice in the Description page of Project Settings.


#include "MainActor.h"
#include "Actors/FP06Train.h"

// Sets default values
AMainActor::AMainActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	/*ConstructorHelpers::FClassFinder<AFP06Train> FindClass(TEXT("/Script/Engine.Blueprint'/Game/Programming/Blueprints/BP_05_Train.BP_05_Train_C'"));
	if (FindClass.Succeeded())
	{
		ActorClass = FindClass.Class;
	}*/
}

// Called when the game starts or when spawned
void AMainActor::BeginPlay()
{
	Super::BeginPlay();
	
	FVector Location(1100, 1000, 50);
	FRotator Rotation(0, 0, 0);

	//AA05Train* Train = GetWorld()->SpawnActor<AA05Train>(Location, Rotation);
	//Train = Cast<AFP06Train>(GetWorld()->SpawnActor(ActorClass));

	//Train->SetLifeSpan(5.0f);
}

// Called every frame
void AMainActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

