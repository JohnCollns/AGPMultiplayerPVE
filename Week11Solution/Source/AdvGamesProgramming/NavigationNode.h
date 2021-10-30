// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NavigationNode.generated.h"

UCLASS()
class ADVGAMESPROGRAMMING_API ANavigationNode : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANavigationNode();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	UPROPERTY(EditAnywhere, Category = "ConnectedNodes")
	TArray<ANavigationNode*> ConnectedNodes;
	USceneComponent* LocationComponent;

	float GScore;
	float HScore;
	ANavigationNode* CameFrom;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	float FScore();

};
