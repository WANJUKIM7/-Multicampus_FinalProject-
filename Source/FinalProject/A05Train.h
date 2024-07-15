// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "A05Train.generated.h"

class UStaticMeshComponent;

UCLASS()
class FINALPROJECT_API AA05Train : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AA05Train();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		TObjectPtr<UStaticMeshComponent> Body;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		TObjectPtr<UStaticMeshComponent> Wing;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		TObjectPtr<UStaticMeshComponent> Head;

	UPROPERTY(EditAnywhere, Category = Battle)
		TObjectPtr<class AActor> Target;
};
