// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/FPPlayerNameWidget.h"
#include "Components/TextBlock.h"
#include "Blueprint/WidgetTree.h"

UFPPlayerNameWidget::UFPPlayerNameWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, Name(nullptr)
{
}

void UFPPlayerNameWidget::NativeConstruct()
{
	Super::NativeConstruct();

	/*if (!Name)
	{
		UE_LOG(LogTemp, Log, TEXT("UFPPlayerNameWidget::NativeConstruct()"));
		Name = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("NameTextBlock"));
		WidgetTree->RootWidget = Name;
	}*/

}

void UFPPlayerNameWidget::SetName(const FText& Text)
{
	if (Name)
	{
		UE_LOG(LogTemp, Log, TEXT("UFPPlayerNameWidget::SetName"));
		FText NewName = FText::FromString(TEXT("Player"));
		Name->SetText(NewName);
		//Name->SetText(Text);
	}
}
