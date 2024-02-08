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

	TArray<AItemBase*> ItemArray;
	Items.GenerateKeyArray(ItemArray);

	bool bFoundItem = false;
	for (AItemBase* InvenItem : ItemArray)
	{
		if (InvenItem->GetDisplayName() == Item->GetDisplayName())
		{
			Items[InvenItem] += 1;
			bFoundItem = true;
			UE_LOG(LogTemp, Warning, TEXT("found Item"));
			break;
		}
	}
	if(bFoundItem == false)
	{
		Items.Add(Item, 1);
		UE_LOG(LogTemp, Warning, TEXT("Added Item"));

	}

	OnInventoryUpdated.Broadcast();

	return true;
}

bool UInventoryComponent::RemoveItem(AItemBase* Item)
{
	if (Item == nullptr)
		return false;
	
	Item->SetOwningInventory(nullptr);

	TArray<AItemBase*> ItemArray;
	Items.GenerateKeyArray(ItemArray);

	AItemBase* ItemToRemove = nullptr;
	for (AItemBase* InvenItem : ItemArray)
	{
		if (InvenItem->GetDisplayName() == Item->GetDisplayName())
		{
			Items[InvenItem] -= 1;
			UE_LOG(LogTemp, Warning, TEXT("found Item"));

			if (Items[InvenItem] <= 0)
				ItemToRemove = InvenItem;
			break;
		}
	}

	if (ItemToRemove)
	{
		Items.Remove(ItemToRemove);
		UE_LOG(LogTemp, Warning, TEXT("Remove Item"));
	}

	OnInventoryUpdated.Broadcast();
	return true;
}

int32 UInventoryComponent::GetItemCount(AItemBase* Item)
{
	if (Item == nullptr) return 0;

	TArray<AItemBase*> ItemArray;
	Items.GenerateKeyArray(ItemArray);

	for (AItemBase* InvenItem : ItemArray)
	{
		if (InvenItem->GetDisplayName() == Item->GetDisplayName())
		{
			return Items[InvenItem];
		}
	}
	return 0;
}

