// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryItemWidget.h"
#include "../Item/ItemBase.h"


UInventoryItemWidget::UInventoryItemWidget(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
}

void UInventoryItemWidget::NativeOnInitialized()
{
}

void UInventoryItemWidget::NativeConstruct()
{
	UE_LOG(LogTemp, Warning, TEXT("Set Name and Thumbnail"));

}

