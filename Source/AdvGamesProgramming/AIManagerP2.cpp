// Fill out your copyright notice in the Description page of Project Settings.


#include "AIManagerP2.h"
#include "EngineUtils.h"
#include "NavigationNodeP2.h"
#include "TentacleBase.h"
#include "EnemyCharacter.h"

// Sets default values
AAIManagerP2::AAIManagerP2()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AllowedAngle = 0.4f;

	RoundNumber = 1;
	EnemyEntities = 0;
	//UE_LOG(LogTemp, Warning, TEXT("Round Number is %d"), RoundNumber);
}

// Called when the game starts or when spawned
void AAIManagerP2::BeginPlay()
{
	Super::BeginPlay();

	if (!this->HasAuthority())
	{
		this->Destroy();
	}

	if (AllNodes.Num() == 0)
	{
		//UE_LOG(LogTemp, Display, TEXT("POPULATING NODES"))
		PopulateNodes();
	}
	for (TActorIterator<ATentacleBase> It(GetWorld()); It; ++It)
	{
		if ((*It)->GetActorLocation().X < 0)
			Tentacles.Add(*It);
	}


	CreateAgents();
	//UE_LOG(LogTemp, Warning, TEXT("Number of nodes: %i"), AllNodes.Num())
}

// Called every frame
void AAIManagerP2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (EnemyEntities == 0 && !PVP)
	{
		GameManager->RoundEnd();
	}

}

TArray<ANavigationNodeP2*> AAIManagerP2::GeneratePath(ANavigationNodeP2* StartNode, ANavigationNodeP2* EndNode)
{

	// Create the open set array and add the start node
	TArray<ANavigationNodeP2*> OpenSet;
	OpenSet.Add(StartNode);

	// Set all the GScores to infinity
	for (auto It = AllNodes.CreateIterator(); It; ++It)
	{
		(*It)->GScore = TNumericLimits<float>::Max();
	}

	// Set start node GScore to zero and update the heuristic
	StartNode->GScore = 0.0f;
	StartNode->HScore = FVector::Dist(StartNode->GetActorLocation(), EndNode->GetActorLocation());

	ANavigationNodeP2* CurrentNode;

	// Loop through the open set until it is empty
	while (OpenSet.Num() > 0)
	{
		// Find the node with the lowest FScore
		ANavigationNodeP2* BestNode = OpenSet[0];
		for (auto It = OpenSet.CreateConstIterator(); It; ++It)
		{
			// If the best node is the current node then skip
			if (*It == BestNode) continue;
			// If the current nodes fscore is better than the 
			// best nodes fscore then set the current node as the best node
			if ((*It)->FScore() < BestNode->FScore())
			{
				BestNode = *It;
			}
		}
		// When this loop finishes, the BestNode will be the node with the lowest FScore in the open set
		CurrentNode = BestNode;
		OpenSet.Remove(CurrentNode);

		// If the current node is the end node then we have the path and should reconstruct it
		if (CurrentNode == EndNode)
		{
			return ReconstructPath(StartNode, EndNode);
		}

		// Loop through all of the connected nodes of the current node
		for (auto It = CurrentNode->ConnectedNodes.CreateIterator(); It; ++It)
		{
			float TentativeGScore = CurrentNode->GScore + FVector::Dist(CurrentNode->GetActorLocation(), (*It)->GetActorLocation());
			if (TentativeGScore < (*It)->GScore)
			{
				(*It)->CameFrom = CurrentNode;
				(*It)->GScore = TentativeGScore;
				(*It)->HScore = FVector::Dist((*It)->GetActorLocation(), EndNode->GetActorLocation());
				if (!OpenSet.Contains(*It))
				{
					OpenSet.Add(*It);
				}
			}
		}
	}

	// If it exists this loop then no valid path has been found so return an empty path.

	return TArray<ANavigationNodeP2*>();

}

TArray<ANavigationNodeP2*> AAIManagerP2::ReconstructPath(ANavigationNodeP2* StartNode, ANavigationNodeP2* EndNode)
{
	TArray<ANavigationNodeP2*> Path;
	ANavigationNodeP2* CurrentNode = EndNode;
	while (CurrentNode != StartNode)
	{
		Path.Add(CurrentNode);
		CurrentNode = CurrentNode->CameFrom;
	}
	return Path;
}

void AAIManagerP2::PopulateNodes_Implementation()
{
	for (TActorIterator<ANavigationNodeP2> It(GetWorld()); It; ++It)
	{
		AllNodes.Add(*It);
	}
}

void AAIManagerP2::CreateAgents_Implementation()
{
	if (AllNodes.Num() > 0)
	{
		NumAI = RoundNumber;
		for (int32 i = 0; i < NumAI; i++)
		{
			float RandomEnemyType = FMath::RandRange(0.0f, 1.0f);
			if (RandomEnemyType < 0.50f && Players.Num() > 0)
			{
				

				UE_LOG(LogTemp, Warning, TEXT("GOT HERE Number of elements in PLayer array %i"), Players.Num())
				UE_LOG(LogTemp, Warning, TEXT("GOT HERE Number of elements in Tentacles array %i"), Tentacles.Num())
				UE_LOG(LogTemp, Warning, TEXT("Name of the player: %s"), *Players[0]->GetName())

				AActor* PlayerTarget = nullptr;// = Cast<AActor>();
				for (TActorIterator<APlayerCharacter> It(GetWorld()); It; ++It)
				{
					PlayerTarget = *It;
				}

				int32 RandomTentacle = FMath::RandRange(0, Tentacles.Num() - 1);

				float TentacleRarity = FMath::RandRange(0.0f, 1.0f);

				if (TentacleRarity <= 0.05f && Players.Num() > 0)
				{
					Tentacles[RandomTentacle]->SetFromRarity(EWeaponPickupRarity::LEGENDARY, PlayerTarget);
				}
				else if (TentacleRarity <= 0.20f && Players.Num() > 0)
				{
					Tentacles[RandomTentacle]->SetFromRarity(EWeaponPickupRarity::MASTER, PlayerTarget);
				}
				else if (TentacleRarity <= 0.50f && Players.Num() > 0)
				{

					Tentacles[RandomTentacle]->SetFromRarity(EWeaponPickupRarity::RARE, PlayerTarget);
				}
				else if (Players.Num() > 0)
				{
					Tentacles[RandomTentacle]->SetFromRarity(EWeaponPickupRarity::COMMON, PlayerTarget);
				}
				
				/*if (TentacleRarity <= 0.05f)
				{
					Tentacles[RandomTentacle]->SetFromRarity(EWeaponPickupRarity::LEGENDARY, Players[0]);
				}
				else if (TentacleRarity <= 0.20f)
				{
					Tentacles[RandomTentacle]->SetFromRarity(EWeaponPickupRarity::MASTER, Players[0]);
				}
				else if (TentacleRarity <= 0.50f)
				{
					Tentacles[RandomTentacle]->SetFromRarity(EWeaponPickupRarity::RARE, Players[0]);
				}
				else
				{
					Tentacles[RandomTentacle]->SetFromRarity(EWeaponPickupRarity::COMMON, Players[0]);
				}*/
					
				
			}
			else
			{
				// Get a random node index
				int32 NodeIndex = FMath::RandRange(0, AllNodes.Num() - 1);
				AEnemyCharacter* SpawnedEnemy = GetWorld()->SpawnActor<AEnemyCharacter>(RegularEnemy, AllNodes[NodeIndex]->GetActorLocation(), AllNodes[NodeIndex]->GetActorRotation());
				SpawnedEnemy->ManagerP2 = this;
				SpawnedEnemy->SetModifier();
				SpawnedEnemy->SetStats();
				SpawnedEnemy->CurrentNodeP2 = AllNodes[NodeIndex];
				EnemyEntities += 1;
				UE_LOG(LogTemp, Warning, TEXT("Number of enemies left is : %i"), EnemyEntities)
			}
		}
	}

	//UE_LOG(LogTemp, Warning, TEXT("NumAI is %d"), NumAI);
}

ANavigationNodeP2* AAIManagerP2::FindNearestNode(const FVector& Location)
{
	ANavigationNodeP2* NearestNode = nullptr;
	float NearestDistance = TNumericLimits<float>::Max();
	//Loop through the nodes and find the nearest one in distance
	for (ANavigationNodeP2* CurrentNode : AllNodes)
	{
		float CurrentNodeDistance = FVector::Distance(Location, CurrentNode->GetActorLocation());
		if (CurrentNodeDistance < NearestDistance)
		{
			NearestDistance = CurrentNodeDistance;
			NearestNode = CurrentNode;
		}
	}
	//UE_LOG(LogTemp, Error, TEXT("Nearest Node: %s"), *NearestNode->GetName())
	return NearestNode;
}

ANavigationNodeP2* AAIManagerP2::FindFurthestNode(const FVector& Location)
{
	ANavigationNodeP2* FurthestNode = nullptr;
	float FurthestDistance = 0.0f;
	//Loop through the nodes and find the nearest one in distance
	for (ANavigationNodeP2* CurrentNode : AllNodes)
	{
		float CurrentNodeDistance = FVector::Distance(Location, CurrentNode->GetActorLocation());
		if (CurrentNodeDistance > FurthestDistance)
		{
			FurthestDistance = CurrentNodeDistance;
			FurthestNode = CurrentNode;
		}
	}

	//UE_LOG(LogTemp, Error, TEXT("Furthest Node: %s"), *FurthestNode->GetName())
	return FurthestNode;
}

void AAIManagerP2::AddConnection_Implementation(ANavigationNodeP2* FromNode, ANavigationNodeP2* ToNode)
{
	FVector DirectionVector = ToNode->GetActorLocation() - FromNode->GetActorLocation();
	DirectionVector.Normalize();
	if (FMath::Abs(DirectionVector.Z) < AllowedAngle)
	{
		if (!FromNode->ConnectedNodes.Contains(ToNode))
			FromNode->ConnectedNodes.Add(ToNode);

		if (!ToNode->ConnectedNodes.Contains(FromNode))
			ToNode->ConnectedNodes.Add(FromNode);
	}
}

void AAIManagerP2::ReduceEnemyEntities_Implementation()
{
	EnemyEntities -= 1;
	UE_LOG(LogTemp, Warning, TEXT("Number of enemies left is : %i"), EnemyEntities);
}

void AAIManagerP2::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AAIManagerP2, RoundNumber);
	DOREPLIFETIME(AAIManagerP2, EnemyEntities);
}