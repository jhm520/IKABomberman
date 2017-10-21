// Fill out your copyright notice in the Description page of Project Settings.

#include "BomberCharacter.h"



namespace MovementInputVectors
{
	const FVector Up(1, 0, 0);
	const FVector Down(-1, 0, 0);
	const FVector Left(0, -1, 0);
	const FVector Right(0, 1, 0);
}
// Sets default values
ABomberCharacter::ABomberCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	InputMap.Add(EMovementInputEnum::Up, false);
	InputMap.Add(EMovementInputEnum::Down, false);
	InputMap.Add(EMovementInputEnum::Left, false);
	InputMap.Add(EMovementInputEnum::Right, false);

}

// Called when the game starts or when spawned
void ABomberCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABomberCharacter::SetInput(const EMovementInputEnum InInputKey, const bool bPressed)
{
	bool* FoundInput = InputMap.Find(InInputKey);

	const bool InputIsPressed = *FoundInput;

	if (FoundInput && InputIsPressed != bPressed)
	{
		*FoundInput = bPressed;

		if (bPressed)
		{

			switch (InInputKey)
			{
				case EMovementInputEnum::Up:
					InputVector += MovementInputVectors::Up;
					break;
				case EMovementInputEnum::Down:
					InputVector += MovementInputVectors::Down;
					break;
				case EMovementInputEnum::Left:
					InputVector += MovementInputVectors::Left;
					break;
				case EMovementInputEnum::Right:
					InputVector += MovementInputVectors::Right;
					break;
			}
			/*MovementSwitch = InInputKey;
			MovementKeysPressedNum++;*/
		}
		else
		{
			switch (InInputKey)
			{
				case EMovementInputEnum::Up:
					InputVector -= MovementInputVectors::Up;
					break;
				case EMovementInputEnum::Down:
					InputVector -= MovementInputVectors::Down;
					break;
				case EMovementInputEnum::Left:
					InputVector -= MovementInputVectors::Left;
					break;
				case EMovementInputEnum::Right:
					InputVector -= MovementInputVectors::Right;
					break;
			}

			/*if (MovementKeysPressedNum > 0)
			{
				MovementKeysPressedNum--;
			}
			
			if (MovementKeysPressedNum == 0)
			{
				MovementSwitch = EMovementInputEnum::None;
				return;
			}
			else
			{
				for (TPair<EMovementInputEnum, bool> InputPair : InputMap)
				{
					if (InputPair.Value)
					{
						MovementSwitch = InputPair.Key;
						break;
					}
				}
			}*/
		}
	}
}

void ABomberCharacter::TickMovement()
{
	AddMovementInput(InputVector, 1.0f);

	/*switch (MovementSwitch)
	{
		case EMovementInputEnum::None:
			break;
		case EMovementInputEnum::Up:
			AddMovementInput(MovementInputVectors::Up, 1.0f);
			break;
		case EMovementInputEnum::Down:
			AddMovementInput(MovementInputVectors::Down, 1.0f);
			break;
		case EMovementInputEnum::Left:
			AddMovementInput(MovementInputVectors::Left, 1.0f);
			break;
		case EMovementInputEnum::Right:
			AddMovementInput(MovementInputVectors::Right, 1.0f);
			break;
	}*/
}

// Called every frame
void ABomberCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TickMovement();
}

// Called to bind functionality to input
void ABomberCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

