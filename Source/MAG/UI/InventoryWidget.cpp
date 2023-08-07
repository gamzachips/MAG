// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryWidget.h"
#include "Components/VerticalBox.h"
#include "../InventorySystem/InventoryComponent.h"
#include "../MAGCharacterBase.h"
#include "../Item/ItemBase.h"
#include "InventoryItemWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Engine/Texture2D.h"
#include "Components/Image.h"
#include "Components/VerticalBoxSlot.h"
#include "Components/CanvasPanelSlot.h"


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

	TArray<AItemBase*> Items = Inventory->GetItems();

	UE_LOG(LogTemp, Warning, TEXT("number of items : %d"), Items.Num());
	for (AItemBase* Item : Items)
	{
		UE_LOG(LogTemp, Warning, TEXT("Item name : %s"), *FString(Item->GetDisplayName()));
		UInventoryItemWidget* ItemWidget = CreateWidget<UInventoryItemWidget>(this, InventoryItemWidgetClass);

		if (ItemWidget)
		{
			InventoryList->AddChild(ItemWidget);
			UE_LOG(LogTemp, Warning, TEXT("Widget Why!! : %s"), *FString(ItemWidget->GetName()));
			ItemWidget->SetVisibility(ESlateVisibility::Visible);

			ItemWidget->Name->SetText(FText::FromString(Item->GetDisplayName()));
			ItemWidget->Thumbnail->SetBrushFromTexture(Item->GetThumbnail());
		}
	}
}
