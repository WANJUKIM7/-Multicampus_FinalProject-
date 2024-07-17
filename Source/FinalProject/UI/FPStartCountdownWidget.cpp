// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/FPStartCountdownWidget.h"
#include "Components/TextBlock.h"

UFPStartCountdownWidget::UFPStartCountdownWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, Text(nullptr)
	, TimeCountdown(3)
{
}

void UFPStartCountdownWidget::NativeConstruct()
{
	Super::NativeConstruct();

	UpdateCountdownText();

	GetWorld()->GetTimerManager().SetTimer(CountdownTimerHandle, this, &UFPStartCountdownWidget::CountdownTick, 1.0f, true);

}

void UFPStartCountdownWidget::UpdateCountdownText()
{
	if (Text)
	{
		Text->SetText(FText::AsNumber(FMath::Max(0.0f, TimeCountdown)));
	}
}

void UFPStartCountdownWidget::CountdownTick()
{
	if (TimeCountdown > 0)
	{
		TimeCountdown -= 1;
		UpdateCountdownText();

		if (TimeCountdown <= 0)
		{
			GetWorld()->GetTimerManager().ClearTimer(CountdownTimerHandle);
			/*RemoveFromParent();
			ConditionalBeginDestroy();*/
		}
	}
	else
	{

	}
}
