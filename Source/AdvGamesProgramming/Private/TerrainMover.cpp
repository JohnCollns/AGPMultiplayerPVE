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
	Destination = DefaultPosition;
}

// Called every frame
void ATerrainMover::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//if(this->GetActorLocation() != Destination)
	if((GetActorLocation() - Destination).IsNearlyZero())
	{
		this->SetActorLocation(FMath::Lerp(this->GetActorLocation(), Destination, DeltaTime));
		//FMath::Lerp(this->GetActorLocation(), Destination, DeltaTime);
		
	}
}

void ATerrainMover::SetState(int num)
{
	Destination = FVector(DefaultPosition.X + States[num].X, DefaultPosition.Y + States[num].Y, DefaultPosition.Z + States[num].Z);
}

void ATerrainMover::MirrorStates() {
	DefaultPosition = FVector(-DefaultPosition.X, DefaultPosition.Y, DefaultPosition.Z);
	for (int32 i=0; i < States.Num(); i++)
	{
		States[i] = FVector(-States[i].X, States[i].Y, States[i].Z);
	}
	/*for each (FVector MirroredState in States)
	{
		MirroredState = FVector(-MirroredState.X, MirroredState.Y, MirroredState.Z);
	}*/
}