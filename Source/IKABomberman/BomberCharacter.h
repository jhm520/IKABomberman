// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BomberCharacter.generated.h"

UENUM(BlueprintType)
enum class EMovementInputEnum : uint8
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

	EMovementInputEnum MovementSwitch;

	FVector InputVector = FVector(0, 0, 0);

	UFUNCTION(BlueprintCallable, Category = Movement)
	void SetInput(const EMovementInputEnum InInputKey, const bool bPressed);


	TMap<EMovementInputEnum, bool> InputMap;

	int8 MovementKeysPressedNum = 0;


	void TickMovement();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
};
