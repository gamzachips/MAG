// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryWidget.h"
#include "Components/VerticalBox.h"
#include "../InventorySystem/InventoryComponent.h"
#include "../MAGCharacterBase.h"
#include "../Item/ItemBase.h"
#include "InventoryItemWidget.h"
#include "Kismet/GameplayStatics.h"


UInventoryWidget::UInventoryWidget(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	
}

void UInventoryWidget::NativeOnInitialized()
{
	AMAGCharacterBase* Player = Cast<AMAGCharacterBase>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	if (Player)
	{
		Inventory = Player->GetInventory();
	}
}

void UInventoryWidget::NativeConstruct()
{
	RefreshInventory();
}

void UInventoryWidget::RefreshInventory()
{

	InventoryList->ClearChildren();
	if (Inventory == nullptr) return;

	TMap<AItemBase*, int32> Items = Inventory->GetItems();
	TArray<AItemBase*> ItemArray;
	Items.GenerateKeyArray(ItemArray);
	for (AItemBase* Item : ItemArray)
	{
		UInventoryItemWidget* ItemWidget = CreateWidget<UInventoryItemWidget>(this, InventoryItemWidgetClass);

		if (ItemWidget)
		{
			InventoryList->AddChild(ItemWidget);
			ItemWidget->SetVisibility(ESlateVisibility::Visible);

			ItemWidget->SetItem(Item);
			ItemWidget->SetInfo();
			ItemWidget->SetOwner(this);

			//개수 세팅 해야함 
			//개수 안띄워도 개수 줄일 때 튕김
		}
	}
}

