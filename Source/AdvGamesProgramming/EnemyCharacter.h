// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Perception/AIPerceptionTypes.h"
#include "PlayerCharacter.h"
#include "Pickup.h"
#include "RegularPickup.h"
#include "EngineUtils.h"
#include "EnemyCharacter.generated.h"

UENUM()
enum class AgentState : uint8
{
	PATROL,
	ENGAGE,
	EVADE
};

UENUM(BlueprintType)
enum class EEnemyRarity : uint8
{
	LEGENDARY,
	MASTER,
	RARE,
	COMMON
};

UCLASS()
class ADVGAMESPROGRAMMING_API AEnemyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	TArray <class ANavigationNode* > Path;
	ANavigationNode* CurrentNode;
	class AAIManager* Manager;

	UPROPERTY(EditAnywhere, meta = (UIMin = "10.0", UIMax = "1000.0", ClampMin = "10.0", ClampMax = "1000.0"))
		float PathfindingNodeAccuracy;

	class UHealthComponent* HealthComponent;

	UPROPERTY(VisibleAnywhere, Category = "AI")
		AgentState CurrentAgentState;

	class UAIPerceptionComponent* PerceptionComponent;
	AActor* DetectedActor;
	bool bCanSeeActor;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void AgentPatrol();
	void AgentEngage();
	void AgentEvade();

	UFUNCTION()
		void SensePlayer(AActor* ActorSensed, FAIStimulus Stimulus);

	UFUNCTION(BlueprintImplementableEvent)
		void Fire(FVector FireDirection);

	//Rarity Properites

	void SetStats();
	void SetModifier();
	UFUNCTION(BlueprintImplementableEvent)
		void AdjustEnemy();

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		EEnemyRarity EnemyRarity;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		float BulletDamage;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		float MuzzleVelocity;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		int32 MagazineSize;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		float WeaponAccuracy;

	float DifficultyConstant;
	float RoundModifier;

	bool SwarmEnemy;

	UPROPERTY(EditAnywhere, Category = "Drops")
		TSubclassOf<APickup> RegularDrop;
	UPROPERTY(EditAnywhere, Category = "Drops")
		TSubclassOf<APickup> HealthDrop;

	class APlayerCharacter* Player;

	float EnemyRarityIndex;

	void CreateDrop();

private:

	void MoveAlongPath();
	void GenerateRandomBoolArray(int32 ArrayLength, int32 NumTrue, TArray<bool>& RandBoolArray);
};

