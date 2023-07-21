// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ItemWidget.generated.h"

/**
 * 
 */
UCLASS()
class MAG_API UItemWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UItemWidget(const FObjectInitializer& ObjectInitializer);

protected:
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime);

public:
	UFUNCTION()
	void SetItemText(FString Text);

protected:
	UPROPERTY(meta=(BindWidget))
	class UTextBlock* ItemText;

};
