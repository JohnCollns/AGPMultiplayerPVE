// Fill out your copyright notice in the Description page of Project Settings.


#include "RegularPickup.h"

void ARegularPickup::OnGenerate()
{
	APickup::OnGenerate();
	/*
	if (RarityIndex == 4)
	{
		Rarity = EPickupRarity::LEGENDARY;
		RarityModifier = 4.0f;
	}
	else if (RarityIndex == 3)
	{
		Rarity = EPickupRarity::MASTER;
		RarityModifier = 3.0f;
	}
	else if (RarityIndex == 2)
	{
		Rarity = EPickupRarity::RARE;
		RarityModifier = 2.0f;
	}
	else
	{
		Rarity = EPickupRarity::COMMON;
		RarityModifier = 1.0f;
	}
	*/
	float RandomModifier = FMath::RandRange(0.0f, 5.0f);

	if (RandomModifier <= 1.0f)
	{
		PickupStat = EPickupStat::HEALTH;
	}
	else if (RandomModifier <= 2.0f)
	{
		PickupStat = EPickupStat::AMMO;
	}
	else if (RandomModifier <= 3.0f)
	{
		PickupStat = EPickupStat::DAMAGE;
	}
	else
	{
		PickupStat = EPickupStat::VELOCITY;
	}

	PickupBulletDamage = (5);
	PickupMuzzleVelocity = (20);
	PickupMagazineSize = (2);
	PickupWeaponAccuracy = (10);
	PickupHealth = ( 5);
}
