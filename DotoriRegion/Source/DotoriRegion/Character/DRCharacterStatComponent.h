// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DRCharacterStatComponent.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FOnMoveSpeedChanged, float /* MoveSpeed */);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DOTORIREGION_API UDRCharacterStatComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UDRCharacterStatComponent();

protected:
	virtual void BeginPlay() override;

public:
	FOnMoveSpeedChanged OnMoveSpeedChanged;

	FORCEINLINE int32 GetAdditionalTimeLimit() { return AdditionalTimeLimit; }
	FORCEINLINE float GetCaptureBarSize() { return CaptureBarSize; }
	FORCEINLINE float GetProgressGaugeIncreaseAmount() { return ProgressGaugeIncreaseAmount; }
	FORCEINLINE float GetTargetSpeedDecreaseAmount() { return TargetSpeedDecreaseAmount; }
	FORCEINLINE float GetMoveSpeed() { return MoveSpeed; }

	void AddAdditionalTimeLimit(int32 InTimeLimit);
	void AddCpatureBarSize(float InBarSize);
	void AddProgressGaugeIncreaseAmount(float InProgressGaugeAmount);
	void AddTargetSpeedDecreaseAmount(float InTargetSpeedAmount);
	void AddMoveSpeed(float InMoveSpeed);

protected:
	void SetMoveSpeed(float NewMoveSpeed);

	template<typename T>
	T GetLegalValue(T InValue);

protected:
	// Additional time limit for fishing parts.
	UPROPERTY(VisibleAnywhere, Category = Stat)
	int32 AdditionalTimeLimit;

	// The size of capture bar.
	UPROPERTY(VisibleAnywhere, Category = Stat)
	float CaptureBarSize;

	// Rise of gauge when the capture bar comes into contact with a target.
	UPROPERTY(VisibleAnywhere, Category = Stat)
	float ProgressGaugeIncreaseAmount;

	// A reduction in target's speed.
	UPROPERTY(VisibleAnywhere, Category = Stat)
	float TargetSpeedDecreaseAmount;

	// Speed when the character moves.
	UPROPERTY(VisibleAnywhere, Category = Stat)
	float MoveSpeed;
	
	float DefaultMoveSpeed = 500.f;
};