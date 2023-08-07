// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../Interface/PickableInterface.h"
#include "ItemBase.generated.h"

UCLASS(BlueprintType, Blueprintable)
class MAG_API AItemBase : public AActor, public IPickableInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItemBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public: 
	//PickableInterface
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;

	FString GetDisplayName() {return DisplayName;}
	class UTexture2D* GetThumbnail() { return Thumbnail; }
	void SetOwningInventory(class UInventoryComponent* Inventory) { OwningInventory = Inventory; }


protected:
	virtual void Use(class AMAGCharacterBase* Character) {}

	UFUNCTION(BlueprintImplementableEvent)
	void OnUse(class AMAGCharacterBase* Character);



protected:
	UPROPERTY(BlueprintReadOnly)
	bool bHighlighted = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite ,Category="Item")
	class UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	class UTexture2D* Thumbnail;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FString DisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item", meta = (MultiLine = true))
	FString Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item", meta = (ClampMin = 0.0))
	float Weight;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget")
	class UWidgetComponent* WidgetComponent;

	UPROPERTY()
	class UInventoryComponent* OwningInventory;


};
