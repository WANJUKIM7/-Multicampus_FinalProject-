// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FP08CannonBall.generated.h"

UCLASS()
class FINALPROJECT_API AFP08CannonBall : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFP08CannonBall();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TObjectPtr<UStaticMeshComponent> CannonBall = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float CannonBallScale = 1.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float ForwardForceValue = 50.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FVector ForwardVector = FVector(0.0f, 0.0f, 0.0f);
};
