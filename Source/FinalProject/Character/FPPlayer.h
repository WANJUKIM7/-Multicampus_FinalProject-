// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FinalProjectCharacter.h"
#include "FPPlayer.generated.h"

/**
 * 
 */
UCLASS()
class FINALPROJECT_API AFPPlayer : public AFinalProjectCharacter
{
	GENERATED_BODY()
	
public:
	AFPPlayer();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<class USpringArmComponent> CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<class UCameraComponent> FollowCamera;
};
