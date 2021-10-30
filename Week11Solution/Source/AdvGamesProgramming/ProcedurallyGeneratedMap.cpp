// Fill out your copyright notice in the Description page of Project Settings.


#include "ProcedurallyGeneratedMap.h"
#include "KismetProceduralMeshLibrary.h"
#include "AIManager.h"

// Sets default values
AProcedurallyGeneratedMap::AProcedurallyGeneratedMap()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("Mesh Component"));

	PerlinScale = 1000.0f;
	PerlinRoughness = 0.1f;
	bRegenerateMap = false;
}

// Called when the game starts or when spawned
void AProcedurallyGeneratedMap::BeginPlay()
{
	Super::BeginPlay();
	
	/*
	TArray<FVector> Vertices;
	Vertices.Add(FVector(0.0f, 0.0f, 0.0f));
	Vertices.Add(FVector(0.0f, 100.0f, 0.0f));
	Vertices.Add(FVector(100.0f, 100.0f, 0.0f));
	Vertices.Add(FVector(100.0f, 0.0f, 0.0f));

	TArray<int32> Triangles;
	Triangles.Add(0);
	Triangles.Add(1);
	Triangles.Add(3);
	Triangles.Add(3);
	Triangles.Add(1);
	Triangles.Add(2);

	TArray<FVector2D> UVCoords;
	UVCoords.Add(FVector2D(0.0f, 0.0f));
	UVCoords.Add(FVector2D(0.0f, 1.0f));
	UVCoords.Add(FVector2D(1.0f, 1.0f));
	UVCoords.Add(FVector2D(1.0f, 0.0f));

	MeshComponent->CreateMeshSection(0, Vertices, Triangles, TArray<FVector>(), 
		UVCoords, TArray<FColor>(), TArray<FProcMeshTangent>(), true);
	*/

	//GenerateMap();

}

// Called every frame
void AProcedurallyGeneratedMap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bRegenerateMap)
	{
		ClearMap();
		GenerateMap();
		bRegenerateMap = false;
	}
}

bool AProcedurallyGeneratedMap::ShouldTickIfViewportsOnly() const
{
	return true;
}

void AProcedurallyGeneratedMap::GenerateMap()
{
	float PerlinOffset = FMath::RandRange(-10000.0f, 10000.0f);
	for (int32 Y = 0; Y < Height; Y++)
	{
		for (int32 X = 0; X < Width; X++)
		{
			float Z = FMath::PerlinNoise2D(FVector2D(X * PerlinRoughness + PerlinOffset, Y * PerlinRoughness + PerlinOffset)) * PerlinScale;
			Vertices.Add(FVector(X * GridSize, Y * GridSize, Z));
			UVCoords.Add(FVector2D(X, Y));

			if (X != Width - 1 && Y != Height - 1)
			{
				Triangles.Add(Y * Width + X);
				Triangles.Add((Y + 1) * Width + X);
				Triangles.Add(Y * Width + X + 1);
				Triangles.Add(Y * Width + X + 1);
				Triangles.Add((Y + 1) * Width + X);
				Triangles.Add((Y + 1) * Width + X + 1);
			}
		}
	}

	UKismetProceduralMeshLibrary::CalculateTangentsForMesh(Vertices, Triangles, UVCoords, Normals, Tangents);

	MeshComponent->CreateMeshSection(0, Vertices, Triangles, Normals, UVCoords, TArray<FColor>(), Tangents, true);

	UE_LOG(LogTemp, Warning, TEXT("Vertices Count: %i | UVCoords Count: %i | Triangles Count: %i"), Vertices.Num(), UVCoords.Num(), Triangles.Num())

	if (AIManager)
	{
		AIManager->GenerateNodes(Vertices, Width, Height);
	}
}

void AProcedurallyGeneratedMap::ClearMap()
{
	Triangles.Empty();
	Vertices.Empty();
	UVCoords.Empty();
	MeshComponent->ClearAllMeshSections();
}

