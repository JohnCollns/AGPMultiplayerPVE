// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyCharacter.h"
#include "AIManager.h"
#include "AIManagerP2.h"
#include "NavigationNode.h"
#include "NavigationNodeP2.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Perception/AIPerceptionComponent.h"
#include "HealthComponent.h"
#include "Net/UnrealNetwork.h"

// Sets default values
AEnemyCharacter::AEnemyCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CurrentAgentState = AgentState::PATROL;
	PathfindingNodeAccuracy = 100.0f;

	DifficultyConstant = 1.15;

	for (TObjectIterator<APlayerCharacter> Itr; Itr; ++Itr)
	{
		if (Itr->IsA(APlayerCharacter::StaticClass()))
		{
			Player = *Itr;
		}
	}

	if (!this->HasAuthority())
	{
		this->Destroy();
	}
}

// Called when the game starts or when spawned
void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();

	Cast<UCharacterMovementComponent>(GetMovementComponent())->bOrientRotationToMovement = true;
	HealthComponent = FindComponentByClass<UHealthComponent>();
	if (HealthComponent)
	{
		HealthComponent->Enemy = this;
	}

	PerceptionComponent = FindComponentByClass<UAIPerceptionComponent>();
	if (PerceptionComponent)
	{
		PerceptionComponent->OnTargetPerceptionUpdated.AddDynamic(this, &AEnemyCharacter::SensePlayer);
	}

	DetectedActor = nullptr;
	bCanSeeActor = false;
}

// Called every frame
void AEnemyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (CurrentAgentState == AgentState::PATROL)
	{
		if (Manager)
		{
			AgentPatrol();
			if (bCanSeeActor && HealthComponent->HealthPercentageRemaining() >= 40.0f)
			{
				CurrentAgentState = AgentState::ENGAGE;
				Path.Empty();
			}
			else if (bCanSeeActor && HealthComponent->HealthPercentageRemaining() < 40.0f)
			{
				CurrentAgentState = AgentState::EVADE;
				Path.Empty();
			}
		}

		else if (ManagerP2)
		{
			AgentPatrol();
			if (bCanSeeActor && HealthComponent->HealthPercentageRemaining() >= 40.0f)
			{
				CurrentAgentState = AgentState::ENGAGE;
				PathP2.Empty();
			}
			else if (bCanSeeActor && HealthComponent->HealthPercentageRemaining() < 40.0f)
			{
				CurrentAgentState = AgentState::EVADE;
				PathP2.Empty();
			}
		}
		
	}
	else if (CurrentAgentState == AgentState::ENGAGE)
	{
		AgentEngage();
		if (!bCanSeeActor)
		{
			CurrentAgentState = AgentState::PATROL;
		}
		else if (bCanSeeActor && HealthComponent->HealthPercentageRemaining() < 40.0f)
		{
			CurrentAgentState = AgentState::EVADE;
			if (Manager)
				Path.Empty();
			else if (ManagerP2)
				PathP2.Empty();
		}
	}
	else if (CurrentAgentState == AgentState::EVADE)
	{
		AgentEvade();
		if (!bCanSeeActor)
		{
			CurrentAgentState = AgentState::PATROL;
		}
		else if (bCanSeeActor && HealthComponent->HealthPercentageRemaining() >= 40.0f)
		{
			CurrentAgentState = AgentState::ENGAGE;
			if (Manager)
				Path.Empty();
			else if (ManagerP2)
				PathP2.Empty();
		}
	}
	MoveAlongPath();
}

// Called to bind functionality to input
void AEnemyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AEnemyCharacter::AgentPatrol()
{
	
	if (Path.Num() == 0 && Manager)
	{
		Path = Manager->GeneratePath(CurrentNode, Manager->AllNodes[FMath::RandRange(0, Manager->AllNodes.Num() - 1)]);
	}

	else if (PathP2.Num() == 0 && ManagerP2)
	{
		PathP2 = ManagerP2->GeneratePath(CurrentNodeP2, ManagerP2->AllNodes[FMath::RandRange(0, ManagerP2->AllNodes.Num() - 1)]);
	}
	
}

void AEnemyCharacter::AgentEngage()
{
	
	if (bCanSeeActor && DetectedActor)
	{
		FVector FireDirection = DetectedActor->GetActorLocation() - GetActorLocation();
		Fire(FireDirection);
	}

	if (Path.Num() == 0 && DetectedActor && Manager)
	{
		ANavigationNode* NearestNode = Manager->FindNearestNode(DetectedActor->GetActorLocation());
		Path = Manager->GeneratePath(CurrentNode, NearestNode);
	}

	else if (PathP2.Num() == 0 && DetectedActor && ManagerP2)
	{
		ANavigationNodeP2* NearestNode = ManagerP2->FindNearestNode(DetectedActor->GetActorLocation());
		PathP2 = ManagerP2->GeneratePath(CurrentNodeP2, NearestNode);
	}
	
}

void AEnemyCharacter::AgentEvade()
{
	
	if (bCanSeeActor && DetectedActor)
	{
		FVector FireDirection = DetectedActor->GetActorLocation() - GetActorLocation();
		Fire(FireDirection);
	}

	if (Path.Num() == 0 && DetectedActor && Manager)
	{
		ANavigationNode* FurthestNode = Manager->FindFurthestNode(DetectedActor->GetActorLocation());
		Path = Manager->GeneratePath(CurrentNode, FurthestNode);
	}

	else if (PathP2.Num() == 0 && DetectedActor && ManagerP2)
	{
		ANavigationNodeP2* FurthestNode = ManagerP2->FindFurthestNode(DetectedActor->GetActorLocation());
		PathP2 = ManagerP2->GeneratePath(CurrentNodeP2, FurthestNode);
	}
	
}

void AEnemyCharacter::SensePlayer_Implementation(AActor* ActorSensed, FAIStimulus Stimulus)
{
	
	if (Stimulus.WasSuccessfullySensed())
	{
		//UE_LOG(LogTemp, Warning, TEXT("Player Detected"))
		DetectedActor = ActorSensed;
		bCanSeeActor = true;
	}
	else
	{
		//UE_LOG(LogTemp, Warning, TEXT("Player Lost"))
		bCanSeeActor = false;
	}
	
}

void AEnemyCharacter::MoveAlongPath()
{
	if (GetLocalRole() == ROLE_Authority)
	{
		if (Manager)
		{
			if ((GetActorLocation() - CurrentNode->GetActorLocation()).IsNearlyZero(PathfindingNodeAccuracy)
				&& Path.Num() > 0)
			{
				CurrentNode = Path.Pop();
			}
			else if (!(GetActorLocation() - CurrentNode->GetActorLocation()).IsNearlyZero(PathfindingNodeAccuracy))
			{
				AddMovementInput(CurrentNode->GetActorLocation() - GetActorLocation());
			}
		}
		
		else if (ManagerP2)
		{
			if ((GetActorLocation() - CurrentNodeP2->GetActorLocation()).IsNearlyZero(PathfindingNodeAccuracy)
				&& PathP2.Num() > 0)
			{
				CurrentNodeP2 = PathP2.Pop();
			}
			else if (!(GetActorLocation() - CurrentNodeP2->GetActorLocation()).IsNearlyZero(PathfindingNodeAccuracy))
			{
				AddMovementInput(CurrentNodeP2->GetActorLocation() - GetActorLocation());
			}
		}
	}
}

void AEnemyCharacter::GenerateRandomBoolArray(int32 ArrayLength, int32 NumTrue, TArray<bool>& RandBoolArray)
{
	for (int32 i = 0; i < ArrayLength; i++)
	{
		//Ternary Condition
		RandBoolArray.Add(i < NumTrue ? true : false);
	}

	//Card Shuffling Algorithm
	for (int32 i = 0; i < RandBoolArray.Num(); i++)
	{
		int32 RandIndex = FMath::RandRange(0, RandBoolArray.Num() - 1);
		bool Temp = RandBoolArray[i];
		RandBoolArray[i] = RandBoolArray[RandIndex];
		RandBoolArray[RandIndex] = Temp;
	}
}

void AEnemyCharacter::SetModifier_Implementation()
{
	if (Manager)
	{
		RoundModifier = pow(DifficultyConstant, Manager->RoundNumber - 1);
		if (SwarmEnemy)
		{
			RoundModifier /= 2;
		}
	}

	else if (ManagerP2)
	{
		RoundModifier = pow(DifficultyConstant, ManagerP2->RoundNumber - 1);
		if (SwarmEnemy)
		{
			RoundModifier /= 2;
		}
	}
}

void AEnemyCharacter::SetStats()
{
	
	float RarityValue = FMath::RandRange(0.0f, 1.0f);
	TArray<bool> RandBoolArray;

	if (RarityValue <= 0.05f)
	{
		EnemyRarity = EEnemyRarity::LEGENDARY;
		GenerateRandomBoolArray(4, 4, RandBoolArray);
		HealthComponent->MaxHealth *= (1.3 * RoundModifier);
		HealthComponent->setHealth();
		EnemyRarityIndex = 4;
	}
	else if (RarityValue <= 0.20f)
	{
		EnemyRarity = EEnemyRarity::MASTER;
		GenerateRandomBoolArray(4, 3, RandBoolArray);
		HealthComponent->MaxHealth *= (1.2 * RoundModifier);
		HealthComponent->setHealth();
		EnemyRarityIndex = 3;
	}
	else if (RarityValue <= 0.50f)
	{
		EnemyRarity = EEnemyRarity::RARE;
		GenerateRandomBoolArray(4, 1, RandBoolArray);
		HealthComponent->MaxHealth *= (1.1 * RoundModifier);
		HealthComponent->setHealth();
		EnemyRarityIndex = 2;
	}
	else
	{
		EnemyRarity = EEnemyRarity::COMMON;
		GenerateRandomBoolArray(4, 0, RandBoolArray);
		HealthComponent->MaxHealth *= RoundModifier;
		HealthComponent->setHealth();
		EnemyRarityIndex = 1;
	}

	//Assign the good or bad weapon characteristics based on the result of the random boolean array.
	BulletDamage = (RandBoolArray[0] ? FMath::RandRange(15.0f, 30.0f) * RoundModifier : FMath::RandRange(2.0f, 15.0f) * RoundModifier);
	MuzzleVelocity = (RandBoolArray[1] ? FMath::RandRange(10000.0f, 20000.0f) * RoundModifier : FMath::RandRange(5000.0f, 10000.0f) * RoundModifier);
	MagazineSize = (RandBoolArray[2] ? FMath::RandRange(20, 100) * RoundModifier : FMath::RandRange(1, 20) * RoundModifier);
	WeaponAccuracy = (RandBoolArray[3] ? FMath::RandRange(0.95f, 1.0f) * RoundModifier : FMath::RandRange(0.8f, 0.95f) * RoundModifier);

	AdjustEnemy();
	
}

void AEnemyCharacter::CreateDrop_Implementation()
{
	//GetWorld()->SpawnActor<APickup>(RegularDrop, this->GetActorLocation(), this->GetActorRotation());

	float HealthDropChance = FMath::RandRange(0.0f, 100.0f);
	UE_LOG(LogTemp, Warning, TEXT("Create Drop Called"));

	if (HealthDropChance >= Player->HealthComponent->HealthPercentageRemaining())
	{
		GetWorld()->SpawnActor<APickup>(HealthDrop, this->GetActorLocation(), this->GetActorRotation());
	}
	else
	{
		for (int i = 0; i < EnemyRarityIndex; i++)
		{
			ARegularPickup* Pickup = GetWorld()->SpawnActor<ARegularPickup>(RegularDrop, this->GetActorLocation(), this->GetActorRotation());
		}
	}

}

void AEnemyCharacter::Death()
{
	if (Manager)
	{
		Manager->ReduceEnemyEntities();
	}

	else if (ManagerP2)
	{
		ManagerP2->ReduceEnemyEntities();
	}
}

void AEnemyCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AEnemyCharacter, EnemyRarity);
	DOREPLIFETIME(AEnemyCharacter, BulletDamage);
	DOREPLIFETIME(AEnemyCharacter, MuzzleVelocity);
	DOREPLIFETIME(AEnemyCharacter, MagazineSize);
	DOREPLIFETIME(AEnemyCharacter, WeaponAccuracy);
}