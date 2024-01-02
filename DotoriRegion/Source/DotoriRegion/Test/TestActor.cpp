// Fill out your copyright notice in the Description page of Project Settings.

#include "TestActor.h"
#include "DRGameSingleton.h"
#include "Item/DRItemBase.h"

// Sets default values
ATestActor::ATestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATestActor::BeginPlay()
{
	Super::BeginPlay();
	
	UDRItemBase* Item1 = UDRGameSingleton::Get().CreateToolItem(TEXT("tool_001"));
	Item1->SetQuantity(1);
	UDRItemBase* Item2 = UDRGameSingleton::Get().CreateToolItem(TEXT("tool_003"));
	Item1->SetQuantity(3);

	TestInventory.Add(Item2);
	TestInventory.Add(Item1);
}

// Called every frame
void ATestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
