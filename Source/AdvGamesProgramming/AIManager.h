// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Net/UnrealNetwork.h"
#include "GameManager.h"
#include "AIManager.generated.h"


UCLASS()
class ADVGAMESPROGRAMMING_API AAIManager : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AAIManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere, Category = "AI Properties")
		int32 NumAI;
	UPROPERTY(VisibleAnywhere, Category = "Navigation Nodes")
		TArray<class ANavigationNode*> AllNodes;
	UPROPERTY(VisibleAnywhere, Category = "Agents")
		TArray<class AEnemyCharacter*> AllAgents;
	UPROPERTY(EditAnywhere, Category = "Agents")
		TSubclassOf<AEnemyCharacter> RegularEnemy;
	UPROPERTY(EditAnywhere, Category = "Agents")
		TSubclassOf<AEnemyCharacter> SwarmEnemy;

	UPROPERTY(EditAnywhere)
		float AllowedAngle;

	UPROPERTY(EditAnywhere, Replicated)
	int32 EnemyEntities;
	
	UPROPERTY(EditAnywhere, Replicated)
		int32 RoundNumber;

	UFUNCTION(Server, Reliable)
	void ReduceEnemyEntities();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	TArray<ANavigationNode*> GeneratePath(ANavigationNode* StartNode, ANavigationNode* EndNode);
	UFUNCTION(Server, Reliable)
	void PopulateNodes();
	UFUNCTION(Server, Reliable)
	void CreateAgents();

	/**
	Finds the nearest navigation node from the given location.
	@param Location - The location that you want to find the nearest node from.
	@return NearestNode - The nearest node to the given location.
	*/
	ANavigationNode* FindNearestNode(const FVector& Location);
	/**
	Finds the furthest navigation node from the given location.
	@param Location - The location that you want to find the furthest node from.
	@return FurthestNode - The furthest node from the given location.
	*/
	ANavigationNode* FindFurthestNode(const FVector& Location);

	UFUNCTION(Server, Reliable)
	void AddConnection(ANavigationNode* FromNode, ANavigationNode* ToNode);

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	class AGameManager* GameManager;
	bool PVP;
	bool RoundEnd;

	UPROPERTY(EditAnywhere, Category = "Tentacles")
		TArray<class ATentacleBase*> Tentacles;
	
	UPROPERTY(EditAnywhere, Category = "Players")
		TArray<class APlayerCharacter*> Players;

	//UFUNCTION(Server, Reliable)
	//	void GenerateNodes(const TArray<FVector>& Vertices, int32 Width, int32 Height);
private:

	TArray<ANavigationNode*> ReconstructPath(ANavigationNode* StartNode, ANavigationNode* EndNode);
};