// Fill out your copyright notice in the Description page of Project Settings.


#include "Data/FPInputData.h"
#include "FPLogChannels.h"

const UInputAction* UFPInputData::FindInputActionByTag(const FGameplayTag& InputTag) const
{
	for (const FPInputAction& Action : InputActions)
	{
		if (Action.InputAction && Action.InputTag == InputTag)
		{
			return Action.InputAction;
		}
	}

	UE_LOG(LogFP, Error, TEXT("Can't find InputAction for InputTag [%s]"), *InputTag.ToString());

	return nullptr;
}
