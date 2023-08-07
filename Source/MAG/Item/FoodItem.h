// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemBase.h"
#include "FoodItem.generated.h"

/**
 * 
 */
UCLASS()
class MAG_API AFoodItem : public AItemBase
{
	GENERATED_BODY()
	
public:
	AFoodItem();

protected:
	virtual void BeginPlay() override;
	virtual void Use(class AMAGCharacterBase* Character) override;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item", meta = (ClampMin = 0.0))
	float Fullness;
};
