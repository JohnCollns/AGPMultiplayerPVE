// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
//#include "TentacleSection.h"
#include "UObject/UObjectGlobals.h"
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

	FVector FindEndLocation();
	TArray<float> GetAngles(int Axis);
	float DistanceFromTarget(FVector Target);
	float DistanceFromTarget(FVector Target, TArray<float> Angles, int Axis);

	float PartialGradient(FVector Target, TArray<float> Angles, int Axis, int Index);

	bool IK(FVector Target);
	float GetPreviousSectionAngle(int Index, int Axis);

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
