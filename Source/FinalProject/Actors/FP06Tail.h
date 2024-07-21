// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FP06Tail.generated.h"

UCLASS()
class FINALPROJECT_API AFP06Tail : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFP06Tail();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
    TObjectPtr<class USplineComponent> Tail;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float LifeSpan;
};
