// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TerrainMover.generated.h"

UCLASS()
class ADVGAMESPROGRAMMING_API ATerrainMover : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATerrainMover();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere, Category = "TerrainStates")
	TArray<FVector> States;
	UPROPERTY(EditAnywhere, Category = "TerrainStates")
	FVector DefaultPosition;
	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite, Category = "TerrainStates")
	FVector Destination;

	UFUNCTION()
	void SetState(int num);
	UFUNCTION(NetMulticast, Reliable)
	void MulticastSetState(int32 StateIndex);

	UFUNCTION(BlueprintCallable)
	void MirrorStates();

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};