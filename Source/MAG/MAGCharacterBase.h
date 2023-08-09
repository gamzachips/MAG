// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MAGCharacterBase.generated.h"

UCLASS()
class MAG_API AMAGCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMAGCharacterBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	float GetHealth() { return Health; }
	void IncreaseHealth(float Value) { Health = FMath::Min(Health + Value, MaxHealth); }
	void DecreaseHealth(float Value) { Health = FMath::Max(Health - Value, 0); }

	float GetFullness() { return Fullness; }
	void IncreaseFullness(float Value) { Fullness = FMath::Min(Fullness + Value, MaxFullness); }
	void DecreaseFullness(float Value) { Fullness = FMath::Max(Fullness - Value, 0); }


public:
	class UInventoryComponent* GetInventory() { return Inventory; }
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Health")
	float Health;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Health")
	float MaxHealth;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Fullness")
	float Fullness = 100;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Fullness")
	float MaxFullness = 100;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory)
	class UInventoryComponent* Inventory;


};
