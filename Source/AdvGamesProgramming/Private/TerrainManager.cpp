// Fill out your copyright notice in the Description page of Project Settings.


#include "TerrainManager.h"
#include "EngineUtils.h"
#include "TerrainMover.h"

// Sets default values
ATerrainManager::ATerrainManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATerrainManager::BeginPlay()
{
	Super::BeginPlay();
	for(TActorIterator<ATerrainMover> It(GetWorld()); It; ++It)
	{
		TerrainObjects.Add(*It);
	}
}

// Called every frame
void ATerrainManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if(RunThisShitLmao)
	{
		ShiftStates();
		RunThisShitLmao = false;
	}

}

void ATerrainManager::ShiftStates()
{
	for(auto It = TerrainObjects.CreateIterator(); It; It++)
	{
		(*It)->SetState(FMath::RandRange(0,(*It)->States.Num() -1));
	}
}
