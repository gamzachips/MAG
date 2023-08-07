// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponent.h"
#include "../Item/ItemBase.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	Capacity = 100;

}

void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	Items.Empty();

	if (DefaultItemClass == nullptr)
		return;
	DefaultItem = NewObject<AItemBase>(this, DefaultItemClass);

	AddItem(DefaultItem);
}

bool UInventoryComponent::AddItem(AItemBase* Item)
{
	if (Items.Num() >= Capacity || Item == nullptr)
		return false;

	Item->SetOwningInventory(this);
	Items.Add(Item);

	OnInventoryUpdated.Broadcast();

	return true;
}

bool UInventoryComponent::RemoveItem(AItemBase* Item)
{
	if (Item == nullptr)
		return false;
	
	Item->SetOwningInventory(nullptr);
	Items.RemoveSingle(Item);
	OnInventoryUpdated.Broadcast();
	return true;
}

