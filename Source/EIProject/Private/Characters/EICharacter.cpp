// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/EICharacter.h"

// Sets default values
AEICharacter::AEICharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEICharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEICharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEICharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

