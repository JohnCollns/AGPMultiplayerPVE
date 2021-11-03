// Fill out your copyright notice in the Description page of Project Settings.

#include "AIManager.h"
#include "HealthComponent.h"
#include "Engine/GameEngine.h"
#include "EngineUtils.h"
#include "Net/UnrealNetwork.h"
#include "Kismet/GameplayStatics.h"
#include "PlayerHUD.h"
#include "PlayerCharacter.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	MaxHealth = 100.0f;
	// ...
	if (Enemy)
	{
		for (TObjectIterator<AAIManager> Itr; Itr; ++Itr)
		{
			if (Itr->IsA(AAIManager::StaticClass()))
			{
				Manager = *Itr;
			}
		}
	}
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	CurrentHealth = MaxHealth;

	if (APawn* OwnerPawn = Cast<APawn>(GetOwner()))
	{
		if (GetOwner()->GetLocalRole() == ROLE_Authority && OwnerPawn->IsLocallyControlled())
		{
			UpdateHealthBar();
		}
	}
	
}


// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	/*
	if (GEngine && GetOwner()->GetLocalRole() == ROLE_AutonomousProxy)
	{
		GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Red, FString::Printf(TEXT("Current Health: %f"), CurrentHealth));
	}
	*/
}

void UHealthComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UHealthComponent, CurrentHealth);
}

void UHealthComponent::OnTakeDamage(float Damage)
{
	CurrentHealth -= Damage;
	if (CurrentHealth <= 0.0f)
	{
		CurrentHealth = 0;
		OnDeath();
	}
	if (APawn* OwnerPawn = Cast<APawn>(GetOwner()))
	{
		if (GetOwner()->GetLocalRole() == ROLE_Authority && OwnerPawn->IsLocallyControlled())
		{
			UpdateHealthBar();
		}
	}
	
}

void UHealthComponent::OnDeath()
{
	APlayerCharacter* PlayerCharacter = Cast<APlayerCharacter>(GetOwner());
	if (PlayerCharacter)
	{
		PlayerCharacter->OnDeath();
	}
	if (Manager)
	{
		Manager->ReduceEnemyEntities();
	}
	if (Enemy)
	{
		Enemy->CreateDrop();
	}
}

float UHealthComponent::HealthPercentageRemaining()
{
	return CurrentHealth/MaxHealth * 100.0f;
}

void UHealthComponent::UpdateHealthBar()
{
	if (GetOwner()->GetLocalRole() == ROLE_AutonomousProxy || (GetOwner()->GetLocalRole() == ROLE_Authority && Cast<APawn>(GetOwner())->IsLocallyControlled()))
	{
		APlayerHUD* PlayerHUD = Cast<APlayerHUD>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetHUD());
		if (IsValid(PlayerHUD))
		{
			PlayerHUD->SetPlayerHealthBarPercent(CurrentHealth / MaxHealth);
		}
	}
}

void UHealthComponent::setHealth()
{
	CurrentHealth = MaxHealth;
}
