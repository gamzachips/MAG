// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemBase.h"
#include "GameFramework/PlayerController.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AItemBase::AItemBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

}

// Called when the game starts or when spawned
void AItemBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AItemBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AItemBase::HighlightActor()
{
	bHighlighted = true;
	Mesh->SetRenderCustomDepth(true);
	//¿Ü°û¼± Ã³¸®
}
void AItemBase::UnHighlightActor()
{
	bHighlighted = false;
	Mesh->SetRenderCustomDepth(false);

	//¿Ü°û¼± ÇØÁ¦
}
