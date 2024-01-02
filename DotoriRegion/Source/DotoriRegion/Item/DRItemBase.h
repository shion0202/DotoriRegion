// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DRItemData.h"
#include "DRItemBase.generated.h"

UCLASS()
class DOTORIREGION_API UDRItemBase : public UObject
{
	GENERATED_BODY()
	
public:
	UDRItemBase();

	UFUNCTION()
	FORCEINLINE int32 GetQuantity() { return Quantity; }

	UFUNCTION()
	void SetQuantity(const int32 NewQuantity);

	UFUNCTION()
	virtual void UseItem();

	UFUNCTION()
	virtual void EquipItem(ACharacter* Target);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item)
	FDRItemData ItemData;

	// Need owning Inventory pointer.

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Item, meta = (UMin = 1))
	int32 Quantity;
};
