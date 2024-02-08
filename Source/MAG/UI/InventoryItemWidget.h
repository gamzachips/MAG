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

	virtual void NativeOnInitialized() override;

	//Set
	void SetItem(class AItemBase* ItemTemp) { Item = ItemTemp; }
	void SetInfo();
	void SetOwner(class UInventoryWidget* Owner) { OwnerWidget = Owner; }

protected:
	UFUNCTION()
	void OnButtonPressed();

public:
	//UI
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UButton* ItemButton;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UImage* Thumbnail;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UTextBlock* Name;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UTextBlock* Count;

	//Item&Inventory
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	class AItemBase* Item;

	UPROPERTY()
	class UInventoryWidget* OwnerWidget;
};
