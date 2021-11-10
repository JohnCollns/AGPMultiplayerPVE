// Fill out your copyright notice in the Description page of Project Settings.


#include "GameManager.h"
#include "EngineUtils.h"
#include "AdvGamesProgramming/EnemyCharacter.h"

// Sets default values
AGameManager::AGameManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGameManager::BeginPlay()
{
	Super::BeginPlay();
	
	for (TObjectIterator<AAIManager> Itr; Itr; ++Itr)
	{
		if (Itr->IsA(AAIManager::StaticClass()))
		{
			AIManager = *Itr;
			AIManager->GameManager = this;
		}
	}

	for (TObjectIterator<AAIManagerP2> Itr; Itr; ++Itr)
	{
		if (Itr->IsA(AAIManagerP2::StaticClass()))
		{
			AIManagerP2 = *Itr;
			AIManagerP2->GameManager = this;
		}
	}

	for (TObjectIterator<ATerrainManager> Itr; Itr; ++Itr)
	{
		if (Itr->IsA(ATerrainManager::StaticClass()))
		{
			TerrainManager = *Itr;
		}
	}

	if (!this->HasAuthority())
	{
		this->Destroy();
	}
}

// Called every frame
void AGameManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGameManager::RoundEnd()
{
	if (AIManager && AIManagerP2)
	{
		AIManager->RoundNumber += 1;
		AIManagerP2->RoundNumber += 1;
		if (AIManager->RoundNumber < 4)
		{
			AIManager->CreateAgents();
			AIManagerP2->CreateAgents();
			AIManager->RoundEnd = true;
			AIManagerP2->RoundEnd = true;
		}
		else
		{
			AIManager->PVP = true;
			AIManagerP2->PVP = true;
			PVPRound();
		}
			
	}
}

void AGameManager::PVPRound()
{
	UE_LOG(LogTemp, Warning, TEXT("Destroy all enemies"));

	if (TerrainManager)
	{
		UE_LOG(LogTemp, Warning, TEXT("THE WALL, THE WALL, NEITHER HEAVEN NOR EARTH CAN MAKE HIM FALL"));
	}
}