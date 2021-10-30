// Fill out your copyright notice in the Description page of Project Settings.


#include "PickupManager.h"
#include "Engine/World.h"
#include "Pickup.h"
#include "Engine/Engine.h"


// Sets default values
APickupManager::APickupManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void APickupManager::Init(const TArray<FVector>& PossibleSpawnLocationsArg, TSubclassOf<APickup> WeaponPickupClassArg, float SpawnIntervalArg)
{
	this->PossibleSpawnLocations = PossibleSpawnLocationsArg;
	this->WeaponPickupClass = WeaponPickupClassArg;
	this->SpawnInterval = SpawnIntervalArg;
}

void APickupManager::SpawnWeaponPickup()
{
	int32 RandomLocation = FMath::RandRange(0, PossibleSpawnLocations.Num() - 1);
	APickup* WeaponPickup = GetWorld()->SpawnActor<APickup>(WeaponPickupClass, PossibleSpawnLocations[RandomLocation] + FVector(0.0f,0.0f,50.0f), FRotator::ZeroRotator);
	WeaponPickup->SetLifeSpan(PICKUP_LIFETIME);

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Red, FString::Printf(TEXT("Pickup Spawned")));
	}
}

// Called when the game starts or when spawned
void APickupManager::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(WeaponSpawnTimer, this, &APickupManager::SpawnWeaponPickup, SpawnInterval, true, 0.0f);
	
}

// Called every frame
void APickupManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

