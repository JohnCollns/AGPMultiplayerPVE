// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Pickup.h"
#include "RegularPickup.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class EPickupRarity : uint8
{
	LEGENDARY,
	MASTER,
	RARE,
	COMMON
};

UENUM(BlueprintType)
enum class EPickupStat : uint8
{
	HEALTH,
	AMMO,
	DAMAGE,
	ACCURACY,
	VELOCITY
};

UCLASS()
class ADVGAMESPROGRAMMING_API ARegularPickup : public APickup
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	EPickupRarity Rarity;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	EPickupStat PickupStat;

	int32 RarityIndex;
	float Round;
	float RarityModifier;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		float PickupBulletDamage;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		float PickupMuzzleVelocity;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		int32 PickupMagazineSize;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		float PickupWeaponAccuracy;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		float PickupHealth;

	UFUNCTION(BlueprintImplementableEvent)
		void OnPickup(AActor* ActorThatPickedUp) override;
	UFUNCTION(BlueprintCallable)
		void OnGenerate() override;
};
