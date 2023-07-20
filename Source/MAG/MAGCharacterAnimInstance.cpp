// Fill out your copyright notice in the Description page of Project Settings.


#include "MAGCharacterAnimInstance.h"
#include "Kismet/KismetMathLibrary.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "MAGCharacterBase.h"

void UMAGCharacterAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	Character = Cast<ACharacter>(TryGetPawnOwner());
	if (Character)
		MovementComponent = Character->GetCharacterMovement();
}

void UMAGCharacterAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (MovementComponent == nullptr) return;

	Speed = Character->GetVelocity().Length();
	bIsInAir = MovementComponent->IsFalling();
	Angle = CalculateDirection(Character->GetVelocity(), Character->GetActorRotation());
	bIsCrouched = Character->bIsCrouched;
}
