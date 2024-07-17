// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FPStartCountdownWidget.generated.h"

/**
 * 
 */
UCLASS()
class FINALPROJECT_API UFPStartCountdownWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFPStartCountdownWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	virtual void NativeConstruct() override;

	void UpdateCountdownText();
	void CountdownTick();
protected:
	FTimerHandle CountdownTimerHandle;

	UPROPERTY(meta=(BindWidget), BlueprintReadWrite)
	TObjectPtr<class UTextBlock> Text;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int TimeCountdown;
};
