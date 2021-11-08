// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NavigationNodeP2.generated.h"

UCLASS()
class ADVGAMESPROGRAMMING_API ANavigationNodeP2 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANavigationNodeP2();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	UPROPERTY(EditAnywhere, Category = "ConnectedNodes")
		TArray<ANavigationNodeP2*> ConnectedNodes;
	USceneComponent* LocationComponent;

	float GScore;
	float HScore;
	ANavigationNodeP2* CameFrom;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	float FScore();
};
