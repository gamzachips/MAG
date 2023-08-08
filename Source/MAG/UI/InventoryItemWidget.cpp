// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryItemWidget.h"
#include "../Item/ItemBase.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"

UInventoryItemWidget::UInventoryItemWidget(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
}


void UInventoryItemWidget::SetInfo()
{
	if (Item == nullptr) return;

	Name->SetText(FText::FromString(Item->GetDisplayName()));
	Thumbnail->SetBrushFromTexture(Item->GetThumbnail());
}

