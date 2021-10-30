// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "PlayerHUD.generated.h"

/**
 * 
 */
UCLASS()
class ADVGAMESPROGRAMMING_API APlayerHUD : public AHUD
{
	GENERATED_BODY()

private:

	TSubclassOf<class UUserWidget> PlayerHUDClass;
	UUserWidget* CurrentPlayerHUDWidget;
	class UProgressBar* HealthProgressBar;
	class UTextBlock* RoundsInMagazineText;
	UTextBlock* RoundsRemainingText;

public:

	APlayerHUD();

	void SetPlayerHealthBarPercent(float Percent);
	void HideHUD();
	void ShowHUD();
	UFUNCTION(BlueprintCallable)
	void SetAmmoText(int32 RoundsRemaining, int32 RoundsInMagazine);
	
};
