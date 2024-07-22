// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FP08RotateAuto.generated.h"

UCLASS()
class FINALPROJECT_API AFP08RotateAuto : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFP08RotateAuto();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TObjectPtr<UStaticMeshComponent> Platform;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float RotationSpeed = 1.0f;
};
