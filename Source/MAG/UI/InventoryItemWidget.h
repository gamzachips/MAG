// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InventoryItemWidget.generated.h"

/**
 * 
 */
UCLASS()
class MAG_API UInventoryItemWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UInventoryItemWidget(const FObjectInitializer& ObjectInitializer);



	void SetItem(class AItemBase* ItemTemp) { Item = ItemTemp; }
	void SetInfo();
public:

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UImage* Thumbnail;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UTextBlock* Name;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	class AItemBase* Item;
};
