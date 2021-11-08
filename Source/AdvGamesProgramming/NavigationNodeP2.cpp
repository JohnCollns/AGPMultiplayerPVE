// Fill out your copyright notice in the Description page of Project Settings.


#include "NavigationNodeP2.h"
#include "DrawDebugHelpers.h"

// Sets default values
ANavigationNodeP2::ANavigationNodeP2()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	LocationComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Location Component"));
	RootComponent = LocationComponent;

}

// Called when the game starts or when spawned
void ANavigationNodeP2::BeginPlay()
{
	Super::BeginPlay();

	for (auto It = ConnectedNodes.CreateConstIterator(); It; It++)
	{
		DrawDebugLine(GetWorld(), GetActorLocation(), (*It)->GetActorLocation(), FColor::Blue, true);
	}
	
}

// Called every frame
void ANavigationNodeP2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

float ANavigationNodeP2::FScore()
{
	return GScore + HScore;
}