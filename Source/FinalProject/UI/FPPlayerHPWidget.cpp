// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/FPPlayerHPWidget.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"

UFPPlayerHPWidget::UFPPlayerHPWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, PlayerImage(nullptr)
	, PlayerHP(nullptr)
	, HP(100)
{
}

void UFPPlayerHPWidget::NativeConstruct()
{
	Super::NativeConstruct();
}

void UFPPlayerHPWidget::UpdateHP()
{
	if (PlayerHP)
	{
		PlayerHP->SetText(FText::AsNumber(FMath::Max(0.0f, HP)));
	}
}
