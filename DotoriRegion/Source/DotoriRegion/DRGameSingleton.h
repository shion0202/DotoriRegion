// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Item/DRItemData.h"
#include "DRGameSingleton.generated.h"

UCLASS()
class DOTORIREGION_API UDRGameSingleton : public UObject
{
	GENERATED_BODY()
	
public:
	UDRGameSingleton();
	static UDRGameSingleton& Get();

public:
	FDRItemData GetToolData(FName InId);
	class UDRItemBase* CreateToolItem(FName InId);

private:
	TObjectPtr<UDataTable> ToolTable;
	TObjectPtr<UDataTable> CreatureTable;
	TObjectPtr<UDataTable> MatterTable;
};
