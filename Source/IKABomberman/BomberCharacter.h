// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BomberCharacter.generated.h"


struct FKey;

UENUM(BlueprintType)
enum class EInputEnum : uint8
{
	None	UMETA(DisplayName = "None"),
	Up		UMETA(DisplayName = "Up"),
	Down	UMETA(DisplayName = "Down"),
	Left	UMETA(DisplayName = "Left"),
	Right	UMETA(DisplayName = "Right")
};

UCLASS()
class IKABOMBERMAN_API ABomberCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABomberCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	EInputEnum MovementSwitch;

	FVector InputVector = FVector(0, 0, 0);

	void OnMoveUpPressed();
	void OnMoveUpReleased();

	void OnMoveDownPressed();
	void OnMoveDownReleased();

	void OnMoveLeftPressed();
	void OnMoveLeftReleased();

	void OnMoveRightPressed();
	void OnMoveRightReleased();

	UFUNCTION(BlueprintNativeEvent, Category = "Input")
	void OnPlaceBombPressed();

	UFUNCTION(BlueprintImplementableEvent, Category = "Input")
	void OnDetonatePressed();

	UFUNCTION(BlueprintImplementableEvent, Category = "Bombs")
	void SpawnBomb(int32 ExplosionSize, bool IsRemote);


	UFUNCTION(BlueprintCallable, Category = Input)
	void SetInput(const EInputEnum InInputAction, const bool bPressed);

	TMap<EInputEnum, bool> InputMap;

	int8 MovementKeysPressedNum = 0;

	//Bombs
	UPROPERTY(BlueprintReadWrite, Category = "Bombs")
	int32 CurrentBombs;

	void TickMovement();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
};
