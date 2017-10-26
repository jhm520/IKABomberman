// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BomberGameMode.generated.h"

UENUM(BlueprintType)
enum class EEndGameState : uint8
{
	RedWin,
	RedWin_BlueSuicide,
	BlueWin,
	BlueWin_RedSuicide,
	Draw_TimeRanOut,
	Draw_BothDied
};

UENUM(BlueprintType)
enum class EPlayerColor : uint8
{
	Red,
	Blue
};

/**
 * 
 */
UCLASS()
class IKABOMBERMAN_API ABomberGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
	
	
	
};
