// Fill out your copyright notice in the Description page of Project Settings.


#include "FoodItem.h"
#include "../MAGPlayer.h"



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
	UE_LOG(LogTemp, Warning, TEXT("Fullness = from %f"), Character->GetFullness());

	Character->IncreaseFullness(Fullness);
	UE_LOG(LogTemp, Warning, TEXT("Fullness = %f"), Character->GetFullness());
}
