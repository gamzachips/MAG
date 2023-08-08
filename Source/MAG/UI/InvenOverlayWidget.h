// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InvenOverlayWidget.generated.h"

/**
 * 
 */
UCLASS()
class MAG_API UInvenOverlayWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	class UInventoryWidget* GetInventoryWidget() { return InventoryWidget; }
	
protected:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UInventoryWidget* InventoryWidget;
};
