// Fill out your copyright notice in the Description page of Project Settings.


#include "TerrainManager.h"
#include "EngineUtils.h"
#include "TerrainMover.h"

// Sets default values
ATerrainManager::ATerrainManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	if(!this->HasAuthority())
	{
		this->Destroy();
	}
	//bReplicates = true;
}

// Called when the game starts or when spawned
void ATerrainManager::BeginPlay()
{
	Super::BeginPlay();
	/*if(Instance)
	{
		this->Destroy();
		return;
	}
	else
	{
		Instance = this;
	}*/
	FActorSpawnParameters SpawnParams = FActorSpawnParameters();
	for(TActorIterator<ATerrainMover> It(GetWorld()); It; ++It)
	{
		TerrainObjects.Add(*It);
		//SpawnObjects(*It);
		/*
		// duplicate, mirror and add to MirroredObjects
		SpawnParams.Template = *It;//Cast<ATerrainMover>(*It);
		FVector MirroredLocation = FVector(-(*It)->GetActorLocation().X, 0.0f, 0.0f);
		if(GetWorld())
		{
			GetWorld()->SpawnActor<ATerrainMover>(MirroredLocation, FRotator::ZeroRotator, SpawnParams);
			UE_LOG(LogTemp, Warning, TEXT("SPAWN THE BOI"));
		}

		/*
		//UClass* ClassToSpawn = (*It)->GetClass();
		//ATerrainMover* DuplicatedTerrainMover = GetWorld()->SpawnActor<ATerrainMover>(MirroredLocation, FRotator::ZeroRotator, SpawnParams);
		//AActor* DuplicatedActor = GetWorld()->SpawnActor<AActor>(MirroredLocation, FRotator::ZeroRotator, SpawnParams);
		//ClassToSpawn* DuplicatedActor = GetWorld()->SpawnActor<ClassToSpawn>(MirroredLocation, FRotator::ZeroRotator, SpawnParams);
		AActor* DuplicatedActor = GetWorld()->SpawnActor(ClassToSpawn, &FVector::ZeroVector, &FRotator::ZeroRotator, SpawnParams);
		if (DuplicatedActor) {
			UE_LOG(LogTemp, Warning, TEXT("Successfully spawned a duplicate Terrain Mover (as an AActor)"))
			DuplicatedActor->SetActorLocation(MirroredLocation);
		}
		//ATerrainMover* DuplicatedTerrainMover = GetWorld()->SpawnActor<SpawnableSubclass>(MirroredLocation, FRotator::ZeroRotator, SpawnParams);
		UE_LOG(LogTemp, Warning, TEXT("Successfully spawned a duplicate Terrain Mover (as an AActor)"))
		ATerrainMover* DuplicatedTerrainMover = Cast<ATerrainMover>(DuplicatedActor);
		if (DuplicatedTerrainMover) {
			DuplicatedTerrainMover->MirrorStates();
			MirroredObjects.Add(DuplicatedTerrainMover);
			UE_LOG(LogTemp, Warning, TEXT("Successfully loaded and updated duplicated terrain mover"))
			
		}
		*/
	}
	for (int32 i = 0; i < TerrainObjects.Num(); i++)
		SpawnObjects(TerrainObjects[i]);
	
}

// Called every frame
void ATerrainManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if(RunThisShitLmao)
	{
		ServerShiftStates();
		RunThisShitLmao = false;
	}
	
}

//void ATerrainManager::ShiftStates()
//{
	/*for(auto It = TerrainObjects.CreateIterator(); It; It++)
	{
		(*It)->SetState(FMath::RandRange(0,(*It)->States.Num() -1));
	}*/

/*	for(int32 i = 0; i < TerrainObjects.Num(); i++)
	{
		int32 stateValue = FMath::RandRange(0,TerrainObjects[i]->States.Num()-1);
		TerrainObjects[i]->SetState(stateValue);
		TerrainObjects[i]->MulticastSetState(stateValue);
		MirrorObjects[i]->SetState(stateValue);
		MirrorObjects[i]->MulticastSetState(stateValue);
	}
}*/

void ATerrainManager::ServerShiftStates_Implementation()
{
	for(int32 i = 0; i < TerrainObjects.Num(); i++)
	{
		int32 stateValue = FMath::RandRange(0,TerrainObjects[i]->States.Num()-1);
		TerrainObjects[i]->SetState(stateValue);
		TerrainObjects[i]->MulticastSetState(stateValue);
		MirrorObjects[i]->SetState(stateValue);
		MirrorObjects[i]->MulticastSetState(stateValue);
	}
}


//void ATerrainManager::SpawnObjects(ATerrainMover* Terrain)//SpawnObjects_Implementation
//{
//	
//}

void ATerrainManager::SpawnObjects_Implementation(ATerrainMover* Terrain)//SpawnObjects_Implementation
{

}