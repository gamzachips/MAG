// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MAGPlayerController.generated.h"

/**
 * 
 */

class IPickableInterface;

UCLASS()
class MAG_API AMAGPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AMAGPlayerController();

protected:
	virtual void BeginPlay();
	virtual void PlayerTick(float DeltaTime) override;
	virtual void SetupInputComponent() override;

private:
	//BindAxis
	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);
	void LookUp(float AxisValue);
	void TurnRight(float AxisValue);

	//BindAction
	void CrouchAction();
	void Jump();
	void ShowOrHideInventory();

	//CursorTrace
	void TickCursorTrace();

public:
	IPickableInterface* GetPickableTarget();

private:
	UPROPERTY()
	class ACharacter* OwnerCharacter;

	IPickableInterface* TargetActor;
	
	UPROPERTY(EditAnywhere)
	float ItemPickableDistance = 150;

private:
	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> InventoryWidgetClass;

	UPROPERTY()
	class UUserWidget* InventoryWidget;

	bool bShowingInventory = false;
};
