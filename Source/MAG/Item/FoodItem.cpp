// Fill out your copyright notice in the Description page of Project Settings.


#include "FoodItem.h"
#include "../MAGCharacterBase.h"



AFoodItem::AFoodItem()
{
}

void AFoodItem::BeginPlay()
{
	Super::BeginPlay();
}

void AFoodItem::Use(AMAGCharacterBase* Character)
{
	if (Character == nullptr)
		return;

	Character->IncreaseFullness(Fullness);

}
