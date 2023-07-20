// Fill out your copyright notice in the Description page of Project Settings.


#include "MAGCombatCharacter.h"

AMAGCombatCharacter::AMAGCombatCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	Weapon = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Weapon"));
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void AMAGCombatCharacter::BeginPlay()
{
	Super::BeginPlay();

}

void AMAGCombatCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMAGCombatCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}
