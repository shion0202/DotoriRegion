#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "DRItemData.generated.h"

UENUM(BlueprintType)
enum class EItemType : uint8
{
	Tool = 0,
	Creature,
	Matter
};

UENUM(BlueprintType)
enum class EItemSkillType : uint8
{
	AdditionalTimeLimit = 0,
	CaptureBarSize = 1,
	ProgressGaugeIncreaseAmount = 2,
	TargetSpeedDecreaseAmount = 3,
	MoveSpeed = 4,
	UnlockTarget = 10,
	UnlockSpot = 11
};

USTRUCT(BlueprintType)
struct FDRItemData : public FTableRowBase
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item)
	FText DisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item)
	FText Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item)
	EItemType Type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item)
	TObjectPtr<UTexture2D> Icon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item)
	TArray<FName> IngredientItems;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item)
	TArray<int32> IngredientItemNums;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item)
	TArray<float> IngredientItemProbabilities;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item)
	TArray<EItemSkillType> ItemSkillTypes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item)
	TArray<FString> ItemSkillDetails;
};