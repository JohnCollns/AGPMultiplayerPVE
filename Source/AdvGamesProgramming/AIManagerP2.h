// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Net/UnrealNetwork.h"
#include "GameManager.h"
#include "AIManagerP2.generated.h"


UCLASS()
class ADVGAMESPROGRAMMING_API AAIManagerP2 : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AAIManagerP2();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere, Category = "AI Properties")
		int32 NumAI;
	UPROPERTY(VisibleAnywhere, Category = "Navigation Nodes")
		TArray<class ANavigationNodeP2*> AllNodes;
	UPROPERTY(VisibleAnywhere, Category = "Agents")
		TArray<class AEnemyCharacter*> AllAgents;
	UPROPERTY(EditAnywhere, Category = "Agents")
		TSubclassOf<AEnemyCharacter> RegularEnemy;
	UPROPERTY(EditAnywhere, Category = "Agents")
		TSubclassOf<AEnemyCharacter> SwarmEnemy;

	UPROPERTY(EditAnywhere)
		float AllowedAngle;

	int32 EnemyEntities;

	UPROPERTY(EditAnywhere)
		int32 RoundNumber;

	UFUNCTION(Server, Reliable)
		void ReduceEnemyEntities();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	TArray<ANavigationNodeP2*> GeneratePath(ANavigationNodeP2* StartNode, ANavigationNodeP2* EndNode);
	UFUNCTION(Server, Reliable)
		void PopulateNodes();
	UFUNCTION(Server, Reliable)
		void CreateAgents();

	/**
	Finds the nearest navigation node from the given location.
	@param Location - The location that you want to find the nearest node from.
	@return NearestNode - The nearest node to the given location.
	*/
	ANavigationNodeP2* FindNearestNode(const FVector& Location);
	/**
	Finds the furthest navigation node from the given location.
	@param Location - The location that you want to find the furthest node from.
	@return FurthestNode - The furthest node from the given location.
	*/
	ANavigationNodeP2* FindFurthestNode(const FVector& Location);

	UFUNCTION(Server, Reliable)
		void AddConnection(ANavigationNodeP2* FromNode, ANavigationNodeP2* ToNode);

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	class AGameManager* GameManager;
	bool PVP;
	bool RoundEnd;
private:

	TArray<ANavigationNodeP2*> ReconstructPath(ANavigationNodeP2* StartNode, ANavigationNodeP2* EndNode);
};