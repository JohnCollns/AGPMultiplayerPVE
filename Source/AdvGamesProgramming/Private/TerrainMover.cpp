// Fill out your copyright notice in the Description page of Project Settings.


#include "TerrainMover.h"
#include "Net/UnrealNetwork.h"
#include "EngineUtils.h"

// Sets default values
ATerrainMover::ATerrainMover()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;
}

// Called when the game starts or when spawned
void ATerrainMover::BeginPlay()
{
	Super::BeginPlay();
	DefaultPosition = GetActorLocation(); // we might not want this, as it overrides the editor settings
	Destination = DefaultPosition;
}

// Called every frame
void ATerrainMover::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//if(this->GetActorLocation() != Destination)
	if(!(GetActorLocation() - Destination).IsNearlyZero())
	{
		this->SetActorLocation(FMath::Lerp(this->GetActorLocation(), Destination, DeltaTime));
		//FMath::Lerp(this->GetActorLocation(), Destination, DeltaTime);
		
	}
}

void ATerrainMover::SetState(int num)
{
	if (Role == ROLE_Authority) {
		Destination = FVector(DefaultPosition.X + States[num].X, DefaultPosition.Y + States[num].Y, DefaultPosition.Z + States[num].Z);
		MulticastSetState(num);
	}
	//UE_LOG(LogTemp, Warning, TEXT("%s recieved set state[%i] command, setting destination to: %s"), *GetName(), num, *Destination.ToString())
}

void ATerrainMover::MulticastSetState_Implementation(int32 StateIndex) {
	Destination = FVector(DefaultPosition.X + States[StateIndex].X, DefaultPosition.Y + States[StateIndex].Y, DefaultPosition.Z + States[StateIndex].Z);
	UE_LOG(LogTemp, Warning, TEXT("Client(?): %s recieved set state[%i] command, setting destination to: %f"), *GetName(), StateIndex, Destination.Z)
}

void ATerrainMover::MirrorStates() {
	//DefaultPosition = FVector(-DefaultPosition.X, DefaultPosition.Y, DefaultPosition.Z);
	DefaultPosition = GetActorLocation();
	Destination = DefaultPosition;
	for (int32 i=0; i < States.Num(); i++)
	{
		States[i] = FVector(-States[i].X, States[i].Y, States[i].Z);
	}
	/*for each (FVector MirroredState in States)
	{
		MirroredState = FVector(-MirroredState.X, MirroredState.Y, MirroredState.Z);
	}*/
}

void ATerrainMover::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ATerrainMover, Destination);
}
