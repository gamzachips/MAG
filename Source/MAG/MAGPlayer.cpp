// Fill out your copyright notice in the Description page of Project Settings.


#include "MAGPlayer.h"
#include "InventorySystem/InventoryComponent.h"
#include "Item/ItemBase.h"
#include "Kismet/GameplayStatics.h"
#include "UI/InventoryWidget.h"

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

