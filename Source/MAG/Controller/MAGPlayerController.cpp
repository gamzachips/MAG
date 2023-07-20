// Fill out your copyright notice in the Description page of Project Settings.


#include "MAGPlayerController.h"

AMAGPlayerController::AMAGPlayerController()
{
	
}

void AMAGPlayerController::BeginPlay()
{
	MyPawn = GetPawn();
}

void AMAGPlayerController::SetUpInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAxis(TEXT("MoveForward"), this, &AMAGPlayerController::MoveForward);
	InputComponent->BindAxis(TEXT("MoveRight"), this, &AMAGPlayerController::MoveRight);
	InputComponent->BindAxis(TEXT("LookUp"), this, &AMAGPlayerController::LookUp);
	InputComponent->BindAxis(TEXT("TurnRight"), this, &AMAGPlayerController::TurnRight);
}


void AMAGPlayerController::MoveForward(float AxisValue)
{
	MyPawn->AddMovementInput(MyPawn->GetActorForwardVector(), AxisValue);
}

void AMAGPlayerController::MoveRight(float AxisValue)
{
	MyPawn->AddMovementInput(MyPawn->GetActorRightVector(), AxisValue);

}

void AMAGPlayerController::LookUp(float AxisValue)
{
	MyPawn->AddControllerPitchInput(AxisValue);
}

void AMAGPlayerController::TurnRight(float AxisValue)
{
	MyPawn->AddControllerYawInput(AxisValue);
}

void AMAGPlayerController::TickCursorTrace()
{
	
}
