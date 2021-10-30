// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuWidget.h"
#include "Components/Button.h"
#include "MainGameInstance.h"

void UMainMenuWidget::OnHostButtonPressed()
{
	UE_LOG(LogTemp, Warning, TEXT("Host Button Pressed"))

	//Attempt to create a new session
	if (UMainGameInstance* GameInstance = Cast<UMainGameInstance>(GetGameInstance()))
	{
		GameInstance->CreateSession(TEXT("Test Session"));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Unable to find the GameInstance"))
	}

}

void UMainMenuWidget::OnJoinButtonPressed()
{
	UE_LOG(LogTemp, Warning, TEXT("Join Button Pressed"))
	if (UMainGameInstance* GameInstance = Cast<UMainGameInstance>(GetGameInstance()))
	{
		GameInstance->FindSession(TEXT("Test Session"));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Unable to find GameInstance"))
	}
}

void UMainMenuWidget::OnQuitButtonPressed()
{
	UE_LOG(LogTemp, Warning, TEXT("Quit Button Pressed"))
}

bool UMainMenuWidget::Initialize()
{
	Super::Initialize();
	if (ButtonHost && ButtonJoin && ButtonQuit)
	{
		ButtonHost->OnClicked.AddDynamic(this, &UMainMenuWidget::OnHostButtonPressed);
		ButtonJoin->OnClicked.AddDynamic(this, &UMainMenuWidget::OnJoinButtonPressed);
		ButtonQuit->OnClicked.AddDynamic(this, &UMainMenuWidget::OnQuitButtonPressed);
		return true;
	}
	return false;
}
