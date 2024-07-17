// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FPPlayerNameWidget.generated.h"

/**
 * 
 */
UCLASS()
class FINALPROJECT_API UFPPlayerNameWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFPPlayerNameWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	virtual void NativeConstruct() override;

public:
	void SetName(const FText& Text);

protected:
	UPROPERTY(meta=(BindWidget), BlueprintReadWrite)
	TObjectPtr<class UTextBlock> Name;
};
