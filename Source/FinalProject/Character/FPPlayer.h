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
	void SetViewReduction();
	void SpawnPlayerHPUI();
	void UpdateHPUI(float NewHP);

	float GetHP() { return HP; }
	void SetHP(float NewHP) { /*if (SpotLightCounts == 0) return;*/ HP = NewHP; }

	int GetSpotLightCounts() { return SpotLightCounts; }
	void SetSpotLightCounts(int NewSpotLightCounts) { SpotLightCounts = NewSpotLightCounts; }

	/*UFUNCTION(BlueprintNativeEvent)
	void SpawnSpline();
	virtual void SpawnSpline_Implementation();*/
protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<class USpringArmComponent> CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<class UCameraComponent> FollowCamera;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<class UWidgetComponent> NicknameUI;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<class UFPPlayerHPWidget> PlayerHPUI;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TSubclassOf<class UUserWidget> PlayerHPWidgetClassReference;

	UPROPERTY()
	TObjectPtr<class AFP07PointLight> PointLight;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int SpotLightCounts;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float HP;
};
