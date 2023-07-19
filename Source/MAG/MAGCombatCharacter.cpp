// Fill out your copyright notice in the Description page of Project Settings.


#include "MAGCombatCharacter.h"

void AMAGCombatCharacter::BeginPlay()
{
	Super::BeginPlay();
	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Weapon"));
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void AMAGCombatCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
