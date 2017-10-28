// Fill out your copyright notice in the Description page of Project Settings.

#include "BomberCharacter.h"
#include "GameFramework/InputSettings.h"
#include "GameFramework/PlayerInput.h"



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

	InputMap.Add(EInputEnum::Up, false);
	InputMap.Add(EInputEnum::Down, false);
	InputMap.Add(EInputEnum::Left, false);
	InputMap.Add(EInputEnum::Right, false);
}

// Called when the game starts or when spawned
void ABomberCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABomberCharacter::OnMoveUpPressed()
{
	SetInput(EInputEnum::Up, true);
}

void ABomberCharacter::OnMoveUpReleased()
{
	SetInput(EInputEnum::Up, false);
}

void ABomberCharacter::OnMoveDownPressed()
{
	SetInput(EInputEnum::Down, true);
}

void ABomberCharacter::OnMoveDownReleased()
{
	SetInput(EInputEnum::Down, false);
}

void ABomberCharacter::OnMoveLeftPressed()
{
	SetInput(EInputEnum::Left, true);
}

void ABomberCharacter::OnMoveLeftReleased()
{
	SetInput(EInputEnum::Left, false);
}

void ABomberCharacter::OnMoveRightPressed()
{
	SetInput(EInputEnum::Right, true);
}

void ABomberCharacter::OnMoveRightReleased()
{
	SetInput(EInputEnum::Right, false);
}

void ABomberCharacter::OnPlaceBombPressed_Implementation()
{
}

//void ABomberCharacter::OnPlaceBombPressed()
//{
//
//}

void ABomberCharacter::SetInput(const EInputEnum InInputAction, const bool bPressed)
{
	bool* FoundInput = InputMap.Find(InInputAction);

	const bool InputIsPressed = *FoundInput;

	if (FoundInput && InputIsPressed != bPressed)
	{
		*FoundInput = bPressed;

		if (bPressed)
		{

			switch (InInputAction)
			{
				case EInputEnum::Up:
					InputVector += MovementInputVectors::Up;
					break;
				case EInputEnum::Down:
					InputVector += MovementInputVectors::Down;
					break;
				case EInputEnum::Left:
					InputVector += MovementInputVectors::Left;
					break;
				case EInputEnum::Right:
					InputVector += MovementInputVectors::Right;
					break;
			}
		}
		else
		{
			switch (InInputAction)
			{
				case EInputEnum::Up:
					InputVector -= MovementInputVectors::Up;
					break;
				case EInputEnum::Down:
					InputVector -= MovementInputVectors::Down;
					break;
				case EInputEnum::Left:
					InputVector -= MovementInputVectors::Left;
					break;
				case EInputEnum::Right:
					InputVector -= MovementInputVectors::Right;
					break;
			}
		}
	}
}

void ABomberCharacter::TickMovement()
{
	AddMovementInput(InputVector, 1.0f);
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

	APlayerController* PlayerController = Cast<APlayerController>(GetController());

	if (!PlayerController)
	{
		return;
	}

	const int32 PlayerID = PlayerController->GetLocalPlayer()->GetControllerId();

	if (PlayerID == 0)
	{
		InputComponent->BindAction("P1_MoveUp", IE_Pressed, this, &ABomberCharacter::OnMoveUpPressed);
		InputComponent->BindAction("P1_MoveUp", IE_Released, this, &ABomberCharacter::OnMoveUpReleased);

		InputComponent->BindAction("P1_MoveDown", IE_Pressed, this, &ABomberCharacter::OnMoveDownPressed);
		InputComponent->BindAction("P1_MoveDown", IE_Released, this, &ABomberCharacter::OnMoveDownReleased);

		InputComponent->BindAction("P1_MoveLeft", IE_Pressed, this, &ABomberCharacter::OnMoveLeftPressed);
		InputComponent->BindAction("P1_MoveLeft", IE_Released, this, &ABomberCharacter::OnMoveLeftReleased);

		InputComponent->BindAction("P1_MoveRight", IE_Pressed, this, &ABomberCharacter::OnMoveRightPressed);
		InputComponent->BindAction("P1_MoveRight", IE_Released, this, &ABomberCharacter::OnMoveRightReleased);

		InputComponent->BindAction("P1_PlaceBomb", IE_Pressed, this, &ABomberCharacter::OnPlaceBombPressed);

		InputComponent->BindAction("P1_Detonate", IE_Pressed, this, &ABomberCharacter::OnDetonatePressed);

	}
	else if (PlayerID == 1)
	{
		InputComponent->BindAction("P2_MoveUp", IE_Pressed, this, &ABomberCharacter::OnMoveUpPressed);
		InputComponent->BindAction("P2_MoveUp", IE_Released, this, &ABomberCharacter::OnMoveUpReleased);

		InputComponent->BindAction("P2_MoveDown", IE_Pressed, this, &ABomberCharacter::OnMoveDownPressed);
		InputComponent->BindAction("P2_MoveDown", IE_Released, this, &ABomberCharacter::OnMoveDownReleased);

		InputComponent->BindAction("P2_MoveLeft", IE_Pressed, this, &ABomberCharacter::OnMoveLeftPressed);
		InputComponent->BindAction("P2_MoveLeft", IE_Released, this, &ABomberCharacter::OnMoveLeftReleased);

		InputComponent->BindAction("P2_MoveRight", IE_Pressed, this, &ABomberCharacter::OnMoveRightPressed);
		InputComponent->BindAction("P2_MoveRight", IE_Released, this, &ABomberCharacter::OnMoveRightReleased);

		InputComponent->BindAction("P2_PlaceBomb", IE_Pressed, this, &ABomberCharacter::OnPlaceBombPressed);

		InputComponent->BindAction("P2_Detonate", IE_Pressed, this, &ABomberCharacter::OnDetonatePressed);
	}

}

