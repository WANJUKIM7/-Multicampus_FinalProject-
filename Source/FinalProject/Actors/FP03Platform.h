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

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<class USceneComponent> RootScene = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UStaticMeshComponent> Platform = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<class UBoxComponent> BoxCollision = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<class UBoxComponent> BoxCollision1 = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<class UBoxComponent> BoxCollision2 = nullptr;

	/*UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<class UCurveFloat> FloatCurve;*/

	//FTimeline MaterialTimeline;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TObjectPtr<class UMaterialInstanceDynamic> DynamicMaterialInstance;

	/*UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<class UMaterialInterface> DynamicObject;*/

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool IsTimePassed = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int Durability = 2;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float TimeAfterDuration = 3.0f;

	// Shake
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FVector OriginalLocation;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    FTimerHandle ShakingTimerHandle;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    bool IsShaking = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    float ShakingDuration = 1.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    float ElapsedShakingTime = 0.0f;
};
