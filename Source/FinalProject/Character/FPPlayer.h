// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FPCharacter.h"
#include "FPPlayer.generated.h"

UENUM(BlueprintType)
enum class ECurrentLevel : uint8
{
	E_Level01 UMETA(DisplayName = "Level01"),
	E_Level02 UMETA(DisplayName = "Level02"),
	E_Level03 UMETA(DisplayName = "Level03"),
	E_Level06 UMETA(DisplayName = "Level06")
};

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
	void SetViewDefault();
	void SetSpotLight();
	void SetMovementVelocity(float Value);
	void SpawnPlayerHPUI();
	void UpdateHPUI(float NewHP);
	void SetCurrentLevel(ECurrentLevel level) { E_CurrentLevel = level; }

	float GetHP() { return HP; }
	void SetHP(float NewHP);

	bool GetIsInteracting() { return bIsInteracting; }
	void SetIsInteracting(bool IsInteracting) {  bIsInteracting = IsInteracting; }

	bool GetIsAttachedBomb() { return bIsAttachedBomb; }
	void SetIsAttachedBomb(bool IsAttachedBomb) {  bIsAttachedBomb = IsAttachedBomb; }

	int GetSpotLightCounts() { return SpotLightCounts; }
	void SetSpotLightCounts(int NewSpotLightCounts) { SpotLightCounts = NewSpotLightCounts; }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<class USpringArmComponent> CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<class UCameraComponent> FollowCamera;

public:
	UFUNCTION(BlueprintCallable)
	void DestroyPlayer();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<class UWidgetComponent> NicknameUI;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<class UFPPlayerHPWidget> PlayerHPUI;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TSubclassOf<class UUserWidget> PlayerHPWidgetClassReference;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	ECurrentLevel E_CurrentLevel;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TObjectPtr<class AFP07PointLight> PointLight;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TObjectPtr<class USpotLightComponent> SpotLight;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int SpotLightCounts = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float HP = 100.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool bIsInteracting = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool bIsAttachedBomb = false;
};
