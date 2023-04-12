// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputActionValue.h"
#include "EnhancedInput/Public/InputMappingContext.h"
#include "EIController.generated.h"

UCLASS()
class EIPROJECT_API AEIController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void SetupInputComponent() override;
		
	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	UInputMappingContext* PlayerContext;

	/** InputActions */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* LookAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* MoveAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* JumpAction;

	void Look(const FInputActionValue& Value);
	void Move(const FInputActionValue& Value);
};
