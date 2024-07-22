// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FP04Rock.generated.h"

UCLASS()
class FINALPROJECT_API AFP04Rock : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFP04Rock();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TObjectPtr<UStaticMeshComponent> Rock;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<class USphereComponent> SphereCollision;

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FVector SizeSmall = FVector(0.3f, 0.3f, 0.3f);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FVector SizeMiddle = FVector(0.5f, 0.5f, 0.5f);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FVector SizeLarge = FVector(1.0f, 1.0f, 1.0f);
};
