// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FPPortalEnterLevel.generated.h"

UCLASS()
class FINALPROJECT_API AFPPortalEnterLevel : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFPPortalEnterLevel();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(VisibleAnywhere)
    TObjectPtr<class UNiagaraComponent> PortalEnter;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float ElapsedTime = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool bIsScalingUp = true;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool bIsScalingDown = false;
};
