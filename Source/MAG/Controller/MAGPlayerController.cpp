// Fill out your copyright notice in the Description page of Project Settings.


#include "MAGPlayerController.h"
#include "../Interface/PickableInterface.h"
#include "GameFramework/Character.h"
#include "DrawDebugHelpers.h"

AMAGPlayerController::AMAGPlayerController()
{
	
}

void AMAGPlayerController::BeginPlay()
{
	OwnerCharacter = GetCharacter();
}

void AMAGPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
	TickCursorTrace();
}

void AMAGPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	InputComponent->BindAxis(TEXT("MoveForward"), this, &AMAGPlayerController::MoveForward);
	InputComponent->BindAxis(TEXT("MoveRight"), this, &AMAGPlayerController::MoveRight);
	InputComponent->BindAxis(TEXT("LookUp"), this, &AMAGPlayerController::LookUp);
	InputComponent->BindAxis(TEXT("TurnRight"), this, &AMAGPlayerController::TurnRight);	
	InputComponent->BindAction(TEXT("Crouch"),EInputEvent::IE_Pressed, this, &AMAGPlayerController::CrouchAction);
	InputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &AMAGPlayerController::Jump);
}

void AMAGPlayerController::MoveForward(float AxisValue)
{
	if(OwnerCharacter == nullptr) return;
	OwnerCharacter->AddMovementInput(OwnerCharacter->GetActorForwardVector(),AxisValue);
}

void AMAGPlayerController::MoveRight(float AxisValue)
{
	if(OwnerCharacter == nullptr) return;
	OwnerCharacter->AddMovementInput(OwnerCharacter->GetActorRightVector(), AxisValue);
}

void AMAGPlayerController::LookUp(float AxisValue)
{
	if(OwnerCharacter == nullptr) return;
	OwnerCharacter->AddControllerPitchInput(AxisValue);
}

void AMAGPlayerController::TurnRight(float AxisValue)
{
	if(OwnerCharacter == nullptr) return;
	OwnerCharacter->AddControllerYawInput(AxisValue);
}

void AMAGPlayerController::CrouchAction()
{
	if(OwnerCharacter == nullptr) return;
	if (!OwnerCharacter->bIsCrouched)
		OwnerCharacter->Crouch();
	else
		OwnerCharacter->UnCrouch();
}

void AMAGPlayerController::Jump()
{
	if(OwnerCharacter == nullptr) return;
	OwnerCharacter->Jump();
}

void AMAGPlayerController::TickCursorTrace()
{
	FHitResult CursorHit;
	if(GetHitResultUnderCursor(ECC_Visibility, false, CursorHit)==false)
		return;
	
	int32 x, y;
	GetViewportSize(x, y);
	FHitResult HitResult;
	if(GetHitResultAtScreenPosition(FVector2D(x/2,y/2),ECC_Visibility, false, HitResult) == false)
		return;
		
	IPickableInterface* LocalTargetActor = Cast<IPickableInterface>(HitResult.GetActor());

	float ItemDistance = FVector::Distance(OwnerCharacter->GetActorLocation(), HitResult.GetActor()->GetActorLocation());

	if(LocalTargetActor == nullptr) 
	{
		if(TargetActor)
			TargetActor->UnHighlightActor();
	}
	else 
	{
		if(TargetActor) 
		{
			if(TargetActor!= LocalTargetActor)
			{
				if(ItemDistance < ItemPickableDistance)
					LocalTargetActor->HighlightActor();
				TargetActor->UnHighlightActor();
			}
		}
		else 
		{
			if(ItemDistance < ItemPickableDistance)
				LocalTargetActor->HighlightActor();
		}
	}
	TargetActor = LocalTargetActor;
}

IPickableInterface* AMAGPlayerController::GetPickableTarget()
{
	return TargetActor;
}