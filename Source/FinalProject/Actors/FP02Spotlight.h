// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FP02Spotlight.generated.h"

UCLASS()
class FINALPROJECT_API AFP02Spotlight : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFP02Spotlight();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
public:
	void SetValues(FVector SpawnLocation);
	void SetStartLocation();
	void SetEndLocation();
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Light")
	TObjectPtr<class USpotLightComponent> SpotLight;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Collision")
	TObjectPtr<class USphereComponent> SphereCollision;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<class AFPPlayer> Player = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FVector StartLocation;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FVector EndLocation;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int RandomInteger;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float PerDamage = 5.0f;
};

