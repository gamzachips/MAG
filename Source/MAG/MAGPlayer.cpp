// Fill out your copyright notice in the Description page of Project Settings.


#include "MAGPlayer.h"

AMAGPlayer::AMAGPlayer()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AMAGPlayer::BeginPlay()
{
	Super::BeginPlay();
}

void AMAGPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMAGPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AMAGPlayer::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AMAGPlayer::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis(TEXT("TurnRight"), this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAction(TEXT("Crouch"),EInputEvent::IE_Pressed, this, &AMAGPlayer::CrouchAction);
	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &ACharacter::Jump);
}

void AMAGPlayer::MoveForward(float AxisValue)
{
	AddMovementInput(GetActorForwardVector(), AxisValue);
}

void AMAGPlayer::MoveRight(float AxisValue)
{
	AddMovementInput(GetActorRightVector(), AxisValue);
}

void AMAGPlayer::CrouchAction()
{
	if (!bIsCrouched)
		Crouch();
	else
		UnCrouch();
}
