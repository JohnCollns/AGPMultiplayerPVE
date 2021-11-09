// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TerrainManager.h"

#include ".../AIManager.h"
#include "AIManagerP2.h"
#include "GameManager.generated.h"

UCLASS()
class ADVGAMESPROGRAMMING_API AGameManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGameManager();

	AAIManager* AIManager;
	AAIManagerP2* AIManagerP2;
	class TerrainManager* TerrainManager;

	void RoundEnd();
	void PVPRound();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
