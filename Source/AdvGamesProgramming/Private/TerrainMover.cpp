// Fill out your copyright notice in the Description page of Project Settings.


#include "TerrainMover.h"

#include "EngineUtils.h"

// Sets default values
ATerrainMover::ATerrainMover()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATerrainMover::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATerrainMover::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(this->GetActorLocation() != Destination)
	{
		this->SetActorLocation(Destination);
		FMath::Lerp();
		
	}
}

void ATerrainMover::SetState(int num)
{
	Destination = FVector(default.X + States[num].X,default.Y + States[num].Y,default.Z + States[num].Z);
}

