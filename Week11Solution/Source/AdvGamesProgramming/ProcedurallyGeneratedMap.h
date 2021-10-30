// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralMeshComponent.h"
#include "ProcedurallyGeneratedMap.generated.h"

UCLASS()
class ADVGAMESPROGRAMMING_API AProcedurallyGeneratedMap : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProcedurallyGeneratedMap();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	UPROPERTY(VisibleAnywhere)
	UProceduralMeshComponent* MeshComponent;

	UPROPERTY(EditAnywhere)
	int32 Width;
	UPROPERTY(EditAnywhere)
	int32 Height;
	UPROPERTY(EditAnywhere)
	float GridSize;

	UPROPERTY(EditAnywhere)
	float PerlinScale;
	UPROPERTY(EditAnywhere)
	float PerlinRoughness;

	UPROPERTY(EditAnywhere)
	bool bRegenerateMap;

	UPROPERTY(VisibleAnywhere)
	TArray<FVector> Vertices;

	TArray<int32> Triangles;
	TArray<FVector2D> UVCoords;
	TArray<FVector> Normals;
	TArray<FProcMeshTangent> Tangents;

	UPROPERTY(EditAnywhere)
	class AAIManager* AIManager;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual bool ShouldTickIfViewportsOnly() const override;

	UFUNCTION(BlueprintCallable)
	void GenerateMap();

	void ClearMap();

};
