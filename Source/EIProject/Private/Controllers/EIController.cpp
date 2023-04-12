// Fill out your copyright notice in the Description page of Project Settings.

#include "Controllers/EIController.h"
#include "Characters/EICharacter.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInput/Public/InputActionValue.h"

void AEIController::SetupInputComponent()
{
	Super::SetupInputComponent();
	check(InputComponent);
	
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(this->GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(PlayerContext, 0);
		
		if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
		{
			EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AEIController::Look);
			EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AEIController::Move);
		}
	}

}

void AEIController::Move(const FInputActionValue& Value)
{
	if (this != nullptr)
	{
		const FRotator MovementRotation(0.0f, this->GetControlRotation().Yaw, 0.0f);
		
		if (Value.GetMagnitude() != 0.f)
		{
			// add forward movement
			GetPawn()->AddMovementInput(MovementRotation.RotateVector(FVector::ForwardVector), Value[1]);
			// add right movement
			GetPawn()->AddMovementInput(MovementRotation.RotateVector(FVector::RightVector), Value[0]);
		}
	}
}

void AEIController::Look(const FInputActionValue& Value)
{
	if (this != nullptr)
	{
		AddPitchInput(Value[1] * -1);
		AddYawInput(Value[0]);
	}
}