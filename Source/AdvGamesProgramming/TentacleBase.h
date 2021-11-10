// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
//#include "TentacleSection.h"
#include "WeaponPickup.h"
#include "UObject/UObjectGlobals.h"
#include "AIManager.h"
#include "AIManagerP2.h"
#include "TentacleBase.generated.h"

UCLASS()
class ADVGAMESPROGRAMMING_API ATentacleBase : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ATentacleBase();

	UPROPERTY(EditAnywhere)
	int NumberOfSections;
	UPROPERTY(EditAnywhere)
	float SectionLength;
	UPROPERTY(EditAnywhere)
	bool bTaperThickness;
	UPROPERTY(EditAnywhere)
	float MaxThickness;
	UPROPERTY(EditAnywhere)
	float MinThickness;
	UPROPERTY(EditAnywhere)
	FColor BaseColour;
	UPROPERTY(EditAnywhere)
	FColor TipColour;

	float DynamicSamplingDistance;
	UPROPERTY(EditAnywhere)
	float MaxSample;
	UPROPERTY(EditAnywhere)
	float MinSample;
	void UpdateSamplingDistance();

	float DynamicLearningRate;
	UPROPERTY(EditAnywhere)
	float MaxLearningRate;
	UPROPERTY(EditAnywhere)
	float MinLearningRate;
	void UpdateLearningRate();

	// Dynamism range values. Anything above the max value will result in full speed motion, anything less will result in motion lerped at the rate between the two
	UPROPERTY(EditAnywhere)
	float MaxDynamismRange;
	UPROPERTY(EditAnywhere)
	float MinDynamismRange;
	UPROPERTY(EditAnywhere)
	float EarlyTerminationDistance;

	// Character interacting with variables
	UPROPERTY(EditAnywhere)
	float Damage;
	UPROPERTY(EditAnywhere)
	float PushForceMagnitude;
	UPROPERTY(EditAnywhere)
	float MaxHealth;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float CurrentHealth;
	UPROPERTY(VisibleAnywhere)
	bool bAlive;

	UPROPERTY()
	USceneComponent* Root;

	UPROPERTY(EditAnywhere)
	AActor* TargetActor;

	UPROPERTY(EditAnywhere)
	bool bRegenerateLimb;
	UPROPERTY(EditAnywhere)
	bool bRunIKRealtime;
	UPROPERTY(EditAnywhere)
	bool bRunInPlaymode;
	UPROPERTY(EditAnywhere)
	bool bRunIKOnce;
	UPROPERTY(EditAnywhere)
	bool bDebugLines;
	UPROPERTY(EditAnywhere)
	bool bCalculatePoints;
	UPROPERTY(EditAnywhere)
	bool bCalculateError;
	UPROPERTY(EditAnywhere)
	bool bDisplayRotations;

	virtual bool ShouldTickIfViewportsOnly() const override;

	// Character/gameplay interaction functions
	void SetFromRarity(EWeaponPickupRarity Rarity, AActor* Target);
	UFUNCTION(NetMulticast, Reliable)
	void SetParameters(int NumberOfSections_, float SectionLength_, float MaxThickness_, float MinThickness_, FColor BaseColor_, FColor TipColor_);
	//UFUNCTION(Server, Reliable)
	//bool ServerIK(FVector& const Target);
	void HurtAndPushPlayer(const FVector& Position, AActor* HitActor);
	UFUNCTION(BlueprintCallable)
	void OnTakeDamage(float DamageReceived);
	void OnDeath();

	FVector FindEndLocation();
	TArray<float> GetAngles(int Axis);
	float DistanceFromTarget(FVector Target);
	float DistanceFromTarget(FVector Target, TArray<float> Angles, int Axis);

	float PartialGradient(FVector Target, TArray<float> Angles, int Axis, int Index);

	bool IK(FVector Target);
	float GetPreviousSectionAngle(int Index, int Axis);

	AAIManager* AIManager;
	AAIManagerP2* AIManagerP2;

private:
	UPROPERTY(VisibleAnywhere)
	TArray<class ATentacleSection*> Sections;
	void ConstructLimb();
	void CalculatePoints(); // a function that just prints the locations of the TBase, all sections starts and ends, and the final end point. 

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
