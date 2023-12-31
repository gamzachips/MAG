// Fill out your copyright notice in the Description page of Project Settings.


#include "MAGCharacterBase.h"
#include "InventorySystem/InventoryComponent.h"
#include "Item/ItemBase.h"

// Sets default values
AMAGCharacterBase::AMAGCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Inventory = CreateDefaultSubobject<UInventoryComponent>("Inventory");
	
	MaxHealth = MaxFullness = 100.f;
	Health = Fullness = 100.f;
}

// Called when the game starts or when spawned
void AMAGCharacterBase::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMAGCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMAGCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

