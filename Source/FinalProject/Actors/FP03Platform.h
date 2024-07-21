// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/TimelineComponent.h"
#include "FP03Platform.generated.h"

UCLASS()
class FINALPROJECT_API AFP03Platform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFP03Platform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

public:
	void ChangeMaterial();
	void ChangeMaterialTimeline(float Value);
	void ChangeMaterialFinished();

	UFUNCTION(BlueprintCallable)
	void ShakeAndDestroy();

	void ShakeMesh(float DeltaTime);
	void ReadyToRandomBreak();

	bool GetIsTimePassed() { return IsTimePassed; }

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TObjectPtr<UStaticMeshComponent> Platform;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Collision")
	TObjectPtr<class UBoxComponent> BoxCollision;

	/*UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<class UCurveFloat> FloatCurve;*/

	//FTimeline MaterialTimeline;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TObjectPtr<class UMaterialInstanceDynamic> DynamicMaterialInstance;

	/*UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<class UMaterialInterface> DynamicObject;*/

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool IsTimePassed;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int Durability;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float TimeAfterDuration;

	// Shake
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FVector OriginalLocation;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    FTimerHandle ShakingTimerHandle;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    bool IsShaking;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    float ShakingDuration;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    float ElapsedShakingTime;
};
