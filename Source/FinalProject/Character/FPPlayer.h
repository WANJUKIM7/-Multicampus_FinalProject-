// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FPCharacter.h"
#include "FPPlayer.generated.h"

/**
 * 
 */
UCLASS()
class FINALPROJECT_API AFPPlayer : public AFPCharacter
{
	GENERATED_BODY()
	
public:
	AFPPlayer();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	void SetGravityScale(float Value);

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<class USpringArmComponent> CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<class UCameraComponent> FollowCamera;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<class UWidgetComponent> Nickname;

};
