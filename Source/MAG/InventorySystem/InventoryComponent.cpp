// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponent.h"
#include "../Item/ItemBase.h"

UInventoryComponent::UInventoryComponent()
{
	Capacity = 100;

}

void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	Items.Empty();

	for (auto ItemClass : DefaultItemClasses)
	{
		AItemBase* Item  = NewObject<AItemBase>(this, ItemClass);
		AddItem(Item);
	}
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

