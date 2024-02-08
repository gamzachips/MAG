// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInventoryUpdated);


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MAG_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryComponent();

protected:
	virtual void BeginPlay() override;

public:
	bool AddItem(class AItemBase* Item);
	bool RemoveItem(class AItemBase* Item);
	int32 GetItemCount(class AItemBase* Item);

	TMap<class AItemBase*, int32>& GetItems() { return Items; }

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<TSubclassOf<class AItemBase>> DefaultItemClasses;


	UPROPERTY(EditDefaultsOnly, Category = Inventory)
	int32 Capacity;

	UPROPERTY(BlueprintAssignable, Category = Inventory)
	FOnInventoryUpdated OnInventoryUpdated;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory)
	TMap<class AItemBase*, int32> Items;

};
