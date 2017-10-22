// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameViewportClient.h"
#include "LocalMPViewportClient.generated.h"

/*

This code was taken from https://wiki.unrealengine.com/Local_Multiplayer_Tips#Using_a_Shared_Camera in order to get local multiplayer working

*/
UCLASS()
class IKABOMBERMAN_API ULocalMPViewportClient : public UGameViewportClient
{
	GENERATED_BODY()
	
virtual bool InputKey(FViewport* Viewport, int32 ControllerId, FKey Key, EInputEvent EventType, float AmountDepressed = 1.f, bool bGamepad = false) override;
	
	
};
