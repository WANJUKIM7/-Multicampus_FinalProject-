// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FP01Bomb.generated.h"

UCLASS()
class FINALPROJECT_API AFP01Bomb : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFP01Bomb();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void ResetTimer();

private:
	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TObjectPtr<UStaticMeshComponent> Bomb;

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<class UPointLightComponent> PointLight = nullptr;

	/*UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<class USpotLightComponent> SpotLight = nullptr;*/

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool IsInteracting = false;
		
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float TimeExplode = 10.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float TimeAccumulator = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    bool bIsLightOn = true;
};
