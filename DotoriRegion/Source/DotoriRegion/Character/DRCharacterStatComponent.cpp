// Fill out your copyright notice in the Description page of Project Settings.

#include "DRCharacterStatComponent.h"

UDRCharacterStatComponent::UDRCharacterStatComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	// Default stat values.
	AdditionalTimeLimit = 0;
	CaptureBarSize = 1.f;
	ProgressGaugeIncreaseAmount = 1.f;
	TargetSpeedDecreaseAmount = 0.f;
	MoveSpeed = DefaultMoveSpeed;
}

void UDRCharacterStatComponent::BeginPlay()
{
	Super::BeginPlay();

	SetMoveSpeed(DefaultMoveSpeed);
}

void UDRCharacterStatComponent::AddAdditionalTimeLimit(int32 InTimeLimit)
{
	AdditionalTimeLimit += GetLegalValue<int32>(InTimeLimit);
}

void UDRCharacterStatComponent::AddCpatureBarSize(float InBarSize)
{
	CaptureBarSize += GetLegalValue<float>(InBarSize);
}

void UDRCharacterStatComponent::AddProgressGaugeIncreaseAmount(float InProgressGaugeAmount)
{
	ProgressGaugeIncreaseAmount += GetLegalValue<float>(InProgressGaugeAmount);
}

void UDRCharacterStatComponent::AddTargetSpeedDecreaseAmount(float InTargetSpeedAmount)
{
	TargetSpeedDecreaseAmount += GetLegalValue<float>(InTargetSpeedAmount);
}

void UDRCharacterStatComponent::AddMoveSpeed(float InMoveSpeed)
{
	const float PreMoveSpeed = MoveSpeed;
	const float ActualMoveSpeed = GetLegalValue(InMoveSpeed);
	SetMoveSpeed(PreMoveSpeed + ActualMoveSpeed);
}

void UDRCharacterStatComponent::SetMoveSpeed(float NewMoveSpeed)
{
	// Need AddUObject in character script.
	MoveSpeed = FMath::Clamp(NewMoveSpeed, DefaultMoveSpeed, NewMoveSpeed);
	OnMoveSpeedChanged.Broadcast(MoveSpeed);
}

template<typename T>
inline T UDRCharacterStatComponent::GetLegalValue(T InValue)
{
	const T ActualValue = FMath::Clamp(InValue, 0.f, InValue);
	return ActualValue;
}
