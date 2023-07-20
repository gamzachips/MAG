// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../Interface/PickableInterface.h"
#include "ItemBase.generated.h"

UCLASS()
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

protected: 
	//PickableInterface
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;


protected:
	UPROPERTY(BlueprintReadOnly)
	bool bHighlighted = false;

};
