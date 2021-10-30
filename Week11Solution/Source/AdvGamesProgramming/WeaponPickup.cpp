// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponPickup.h"
#include "Net/UnrealNetwork.h"

void AWeaponPickup::OnGenerate()
{
	APickup::OnGenerate();

	float RarityValue = FMath::RandRange(0.0f, 1.0f);
	TArray<bool> RandBoolArray;

	if (RarityValue <= 0.05f)
	{
		Rarity = EWeaponPickupRarity::LEGENDARY;
		GenerateRandomBoolArray(4, 4, RandBoolArray);
	}
	else if (RarityValue <= 0.20f)
	{
		Rarity = EWeaponPickupRarity::MASTER;
		GenerateRandomBoolArray(4, 3, RandBoolArray);
	}
	else if (RarityValue <= 0.50f)
	{
		Rarity = EWeaponPickupRarity::RARE;
		GenerateRandomBoolArray(4, 1, RandBoolArray);
	}
	else
	{
		Rarity = EWeaponPickupRarity::COMMON;
		GenerateRandomBoolArray(4, 0, RandBoolArray);
	}

	//Assign the good or bad weapon characteristics based on the result of the random boolean array.
	BulletDamage = (RandBoolArray[0] ? FMath::RandRange(15.0f, 30.0f) : FMath::RandRange(2.0f, 15.0f));
	MuzzleVelocity = (RandBoolArray[1] ? FMath::RandRange(10000.0f, 20000.0f) : FMath::RandRange(5000.0f, 10000.0f));
	MagazineSize = (RandBoolArray[2] ? FMath::RandRange(20, 100) : FMath::RandRange(1, 20));
	WeaponAccuracy = (RandBoolArray[3] ? FMath::RandRange(0.95f, 1.0f) : FMath::RandRange(0.8f, 0.95f));
}

void AWeaponPickup::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AWeaponPickup, Rarity);
	DOREPLIFETIME(AWeaponPickup, BulletDamage);
	DOREPLIFETIME(AWeaponPickup, MuzzleVelocity);
	DOREPLIFETIME(AWeaponPickup, MagazineSize);
	DOREPLIFETIME(AWeaponPickup, WeaponAccuracy);
}

void AWeaponPickup::GenerateRandomBoolArray(int32 ArrayLength, int32 NumTrue, TArray<bool>& RandBoolArray)
{
	for (int32 i = 0; i < ArrayLength; i++)
	{
		//Ternary Condition
		RandBoolArray.Add(i < NumTrue ? true : false);
	}

	//Card Shuffling Algorithm
	for (int32 i = 0; i < RandBoolArray.Num(); i++)
	{
		int32 RandIndex = FMath::RandRange(0, RandBoolArray.Num() - 1);
		bool Temp = RandBoolArray[i];
		RandBoolArray[i] = RandBoolArray[RandIndex];
		RandBoolArray[RandIndex] = Temp;
	}
}
