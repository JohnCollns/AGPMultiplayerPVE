// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TerrainMover.h"
#include "GameFramework/Actor.h"
#include "TerrainManager.generated.h"

UCLASS()
class ADVGAMESPROGRAMMING_API ATerrainManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATerrainManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	TArray<ATerrainMover*> TerrainObjects;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	TArray<ATerrainMover*> MirrorObjects;
	/*UPROPERTY(VisibleAnywhere)
	TArray<ATerrainMover*> MirroredObjects;*/
	UPROPERTY(EditAnywhere)
	bool RunThisShitLmao;

	
	//void ShiftStates();

	UFUNCTION(Server, Reliable)
	void ServerShiftStates();

	TSubclassOf<ATerrainMover> SpawnableSubclass;

	static ATerrainManager Instance;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void SpawnObjects(ATerrainMover* Terrain);
	
};
