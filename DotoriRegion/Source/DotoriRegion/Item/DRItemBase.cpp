// Fill out your copyright notice in the Description page of Project Settings.

#include "DRItemBase.h"

UDRItemBase::UDRItemBase()
{

}

void UDRItemBase::SetQuantity(const int32 NewQuantity)
{
	if (NewQuantity != Quantity)
	{
		Quantity = FMath::Clamp(NewQuantity, 0, NewQuantity);
		if (Quantity == 0)
		{
			// If quantity is 0, remove item from inventory.
		}
	}
}

void UDRItemBase::UseItem()
{
	// For creature item, open exchange UI and can exchange creature to matter.
	// It may not need.
}

void UDRItemBase::EquipItem(ACharacter* Target)
{
	// For tool item, increase stat or unlock target and spot.
}
