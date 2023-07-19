// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MAGCharacterBase.h"
#include "MAGCombatCharacter.generated.h"

/**
 * 
 */
UCLASS()
class MAG_API AMAGCombatCharacter : public AMAGCharacterBase
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Combat)
	TObjectPtr<USkeletalMeshComponent> Weapon;
};
