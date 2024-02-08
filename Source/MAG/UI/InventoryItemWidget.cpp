// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryItemWidget.h"
#include "../Item/ItemBase.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"
#include "Components/Button.h"
#include "InventoryWidget.h"
#include "../InventorySystem/InventoryComponent.h"

UInventoryItemWidget::UInventoryItemWidget(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
}

void UInventoryItemWidget::NativeOnInitialized()
{
	ItemButton->OnPressed.AddDynamic(this, &UInventoryItemWidget::OnButtonPressed);
}


void UInventoryItemWidget::SetInfo()
{
	if (Item == nullptr) return;

	Name->SetText(FText::FromString(Item->GetDisplayName()));
	Thumbnail->SetBrushFromTexture(Item->GetThumbnail());

}

void UInventoryItemWidget::SetCount(int32 ItemCount)
{
	if (Item == nullptr) return;
	Count->SetText(FText::FromString(FString::FromInt(ItemCount)));
}

void UInventoryItemWidget::OnButtonPressed()
{
	FButtonStyle Style = ItemButton->WidgetStyle;
	FSlateColor Color = Style.Pressed.TintColor;

	UInventoryItemWidget* PrevSelected = OwnerWidget->GetSelectedItemWidget();
	if (PrevSelected != nullptr && PrevSelected != this)
	{
		//이전에 눌린 버튼이 있었다면 복원시킨다 
		FButtonStyle RestoreStyle = Style;
		Style.Normal.TintColor = Style.Normal.TintColor;
		Style.Hovered.TintColor = Style.Normal.TintColor;
		PrevSelected->ItemButton->SetStyle(RestoreStyle);
	}

	//눌린 나를 바꾼다
	Style.Normal.TintColor = Color;
	Style.Hovered.TintColor = Color;
	ItemButton->SetStyle(Style);

	OwnerWidget->SetSelecteddItemWidget(this);
}


