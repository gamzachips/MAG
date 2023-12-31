// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InventoryWidget.generated.h"

/**
 * 
 */
UCLASS()
class MAG_API UInventoryWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UInventoryWidget(const FObjectInitializer& ObjectInitializer);

	virtual void NativeOnInitialized() override;
	virtual void NativeConstruct() override;
	
	UFUNCTION(BlueprintCallable)
	void RefreshInventory();

	void SetSelecteddItemWidget(class UInventoryItemWidget* ItemWidget) { SelectedItemWidget = ItemWidget; }
	class UInventoryItemWidget* GetSelectedItemWidget() { return SelectedItemWidget; }

protected:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UVerticalBox* InventoryList;

	UPROPERTY(BlueprintReadOnly)
	class UInventoryComponent* Inventory;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<class UInventoryItemWidget> InventoryItemWidgetClass;

	UPROPERTY()
	class UInventoryItemWidget* SelectedItemWidget;

};
