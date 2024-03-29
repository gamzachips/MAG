// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemBase.h"
#include "GameFramework/PlayerController.h"
#include "Components/StaticMeshComponent.h"
#include "../ItemWidget.h"
#include "Components/WidgetComponent.h"
#include "../MAGCharacterBase.h"


// Sets default values
AItemBase::AItemBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SetRootComponent(Mesh);
	Mesh->OnComponentBeginOverlap.AddDynamic(this, &AItemBase::OnOverlap);

	WidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("WidgetComponent"));
	WidgetComponent->SetupAttachment(Mesh);
	WidgetComponent->SetRelativeLocationAndRotation(FVector(0,0,20.f), FRotator(0, 90.f, 0));
	WidgetComponent->SetWidgetSpace(EWidgetSpace::Screen);
	
	Weight = 1;
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
	UItemWidget* Widget =  Cast<UItemWidget>(WidgetComponent->GetWidget());
	if(Widget)
		Widget->SetItemText(DisplayName);
}
void AItemBase::UnHighlightActor()
{
	bHighlighted = false;
	Mesh->SetRenderCustomDepth(false);
	UItemWidget* Widget =  Cast<UItemWidget>(WidgetComponent->GetWidget());
	if(Widget)
		Widget->SetItemText("");

}

void AItemBase::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Mesh->SetSimulatePhysics(false);
	UE_LOG(LogTemp, Warning, TEXT("collision!"));
}
