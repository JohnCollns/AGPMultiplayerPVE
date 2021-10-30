// Fill out your copyright notice in the Description page of Project Settings.


#include "PickupRotator.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UPickupRotator::UPickupRotator()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPickupRotator::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("%s"), *GetOwner()->GetActorLocation().ToString())
}


// Called every frame
void UPickupRotator::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	TickRotateObject(DeltaTime);
}

void UPickupRotator::TickRotateObject(const float& DeltaTime)
{
	FRotator CurrentActorRotation = GetOwner()->GetActorRotation();
	CurrentActorRotation.Yaw += DeltaTime * RotSpeed;
	GetOwner()->SetActorRotation(CurrentActorRotation);
}

