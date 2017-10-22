// Fill out your copyright notice in the Description page of Project Settings.

#include "LocalMPViewportClient.h"

/*

This code was taken from https://wiki.unrealengine.com/Local_Multiplayer_Tips#Using_a_Shared_Camera in order to get local multiplayer working


Basically, whenever an input is pressed, it repeats that same event for all player controllers in the game
*/


bool ULocalMPViewportClient::InputKey(FViewport* Viewport, int32 ControllerId, FKey Key, EInputEvent EventType, float AmountDepressed, bool bGamepad)
{
	if (IgnoreInput() || bGamepad || Key.IsMouseButton())
	{
		return Super::InputKey(Viewport, ControllerId, Key, EventType, AmountDepressed, bGamepad);
	}
	else
	{
		// Propagate keyboard events to all players
		UEngine* const Engine = GetOuterUEngine();
		int32 const NumPlayers = Engine ? Engine->GetNumGamePlayers(this) : 0;
		bool bRetVal = false;
		for (int32 i = 0; i < NumPlayers; i++)
		{
			bRetVal = Super::InputKey(Viewport, i, Key, EventType, AmountDepressed, bGamepad) || bRetVal;
		}

		return bRetVal;
	}
}