// Fill out your copyright notice in the Description page of Project Settings.

#include "DRGameSingleton.h"
#include "Item/DRItemBase.h"

UDRGameSingleton::UDRGameSingleton()
{
	static ConstructorHelpers::FObjectFinder<UDataTable> ToolTableRef(TEXT(
		"/Script/Engine.DataTable'/Game/DotoriRegion/Item/DT_ToolData.DT_ToolData'"));
	if (nullptr != ToolTableRef.Object)
	{
		ToolTable = ToolTableRef.Object;
		check(ToolTable->GetRowMap().Num() > 0);
	}

	static ConstructorHelpers::FObjectFinder<UDataTable> CreatureTableRef(TEXT(
		"/Script/Engine.DataTable'/Game/DotoriRegion/Item/DT_CreatureData.DT_CreatureData'"));
	if (nullptr != CreatureTableRef.Object)
	{
		const UDataTable* DataTable = CreatureTableRef.Object;
		check(DataTable->GetRowMap().Num() > 0);
	}

	static ConstructorHelpers::FObjectFinder<UDataTable> MatterTableRef(TEXT(
		"/Script/Engine.DataTable'/Game/DotoriRegion/Item/DT_MatterData.DT_MatterData'"));
	if (nullptr != MatterTableRef.Object)
	{
		const UDataTable* DataTable = MatterTableRef.Object;
		check(DataTable->GetRowMap().Num() > 0);
	}
}

UDRGameSingleton& UDRGameSingleton::Get()
{
	UDRGameSingleton* Singleton = CastChecked<UDRGameSingleton>(GEngine->GameSingleton);
	if (Singleton)
	{
		return *Singleton;
	}

	return *NewObject<UDRGameSingleton>();
}

FDRItemData UDRGameSingleton::GetToolData(FName InId)
{
	FDRItemData* ToolData = ToolTable->FindRow<FDRItemData>(InId, InId.ToString());
	return *ToolData;
}

UDRItemBase* UDRGameSingleton::CreateToolItem(FName InId)
{
	FDRItemData ItemData = GetToolData(InId);
	UDRItemBase* ToolItem = NewObject<UDRItemBase>(StaticClass());
	ToolItem->ItemData = ItemData;

	return ToolItem;
}
