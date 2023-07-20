// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MAGCombatCharacter.h"
#include "MAGPlayer.generated.h"

/**
 * 
 */
UCLASS()
class MAG_API AMAGPlayer : public AMAGCombatCharacter
{
	GENERATED_BODY()
public:
	AMAGPlayer();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	//Bind Axis/Action
	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);
	void CrouchAction();

};
