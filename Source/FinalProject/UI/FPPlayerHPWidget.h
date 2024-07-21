// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FPPlayerHPWidget.generated.h"

/**
 * 
 */
UCLASS()
class FINALPROJECT_API UFPPlayerHPWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFPPlayerHPWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	virtual void NativeConstruct() override;

	void UpdateHP(float NewHP);

protected:
	FTimerHandle PlayerHPTimerHandle;

	UPROPERTY(meta=(BindWidget), BlueprintReadWrite)
	TObjectPtr<class UImage> PlayerImage;

	UPROPERTY(meta=(BindWidget), BlueprintReadWrite)
	TObjectPtr<class UTextBlock> PlayerHP;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int HP;
};
