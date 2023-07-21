// Fill out your copyright notice in the Description page of Project Settings.

#include "ItemWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Components/TextBlock.h"
#include "Controller/MAGPlayerController.h"
#include "Interface/PickableInterface.h"
#include "Item/ItemBase.h"

UItemWidget::UItemWidget(const FObjectInitializer& ObjectInitializer)
    :Super(ObjectInitializer)
{
}

void UItemWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
    Super::NativeTick(MyGeometry, InDeltaTime);
}

void UItemWidget::SetItemText(FString Text)
{
    ItemText->SetText(FText::FromString(Text));
}
