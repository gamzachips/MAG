// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MAGPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class MAG_API AMAGPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AMAGPlayerController();

protected:
	virtual void BeginPlay();
	virtual void SetUpInputComponent();

private:
	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);
	void LookUp(float AxisValue);
	void TurnRight(float AxisValue);

	void TickCursorTrace();

private:
	UPROPERTY()
	APawn* MyPawn;
};
