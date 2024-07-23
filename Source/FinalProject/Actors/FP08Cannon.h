// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FP08Cannon.generated.h"

UCLASS()
class FINALPROJECT_API AFP08Cannon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFP08Cannon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TObjectPtr<UStaticMeshComponent> Cannon = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    TObjectPtr<class UArrowComponent> ArrowMiddle = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    TObjectPtr<class UArrowComponent> ArrowLeft = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    TObjectPtr<class UArrowComponent> ArrowRight = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool bRandomWay = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float TimeLoopSpawnCannonBall = 3.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float RandomWayValue = 1000.0f;
};
