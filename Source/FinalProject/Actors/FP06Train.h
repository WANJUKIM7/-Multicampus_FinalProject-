// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FP06Train.generated.h"

class UStaticMeshComponent;

UCLASS()
class FINALPROJECT_API AFP06Train : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFP06Train();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		TObjectPtr<UStaticMeshComponent> Train;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		float Speed = 25.0f;
};
