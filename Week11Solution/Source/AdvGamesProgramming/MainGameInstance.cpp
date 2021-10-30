// Fill out your copyright notice in the Description page of Project Settings.


#include "MainGameInstance.h"
#include "UObject/ConstructorHelpers.h"
#include "Blueprint/UserWidget.h"
#include "MainMenuWidget.h"
#include "PlayerCharacter.h"
#include "GameFramework/PlayerController.h"
#include "Interfaces/OnlineSessionInterface.h"

UMainGameInstance::UMainGameInstance(const FObjectInitializer& ObjectInitializer)
{
	static ConstructorHelpers::FClassFinder<UUserWidget> MainMenuWidgetObject(TEXT("/Game/Widgets/MainMenuWidget"));
	MainMenuWidgetClass = MainMenuWidgetObject.Class;
}

void UMainGameInstance::LoadMenu()
{
	if (MainMenuWidgetClass)
	{
		Menu = CreateWidget<UMainMenuWidget>(GetWorld(), MainMenuWidgetClass);
		if (Menu)
		{
			Menu->AddToViewport();

			APlayerController* PlayerController = GetFirstLocalPlayerController();
			if (PlayerController)
			{
				// Set up the settings for the input mode.
				FInputModeUIOnly InputMode;
				InputMode.SetWidgetToFocus(Menu->TakeWidget());
				InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::LockAlways);
				PlayerController->bShowMouseCursor = true;
				PlayerController->SetInputMode(InputMode);
			}
		}
	}
}

void UMainGameInstance::Init()
{
	Subsystem = IOnlineSubsystem::Get();
	if (Subsystem)
	{
		UE_LOG(LogTemp, Warning, TEXT("Found Online Subsystem: %s"), *Subsystem->GetSubsystemName().ToString())
		
		SessionInterface = Subsystem->GetSessionInterface();

		if (SessionInterface.IsValid())
		{
			SessionInterface->OnCreateSessionCompleteDelegates.AddUObject(this, &UMainGameInstance::OnCreateSessionComplete);
			SessionInterface->OnDestroySessionCompleteDelegates.AddUObject(this, &UMainGameInstance::OnDestroySessionComplete);
			SessionInterface->OnFindSessionsCompleteDelegates.AddUObject(this, &UMainGameInstance::OnFindSessionComplete);
			SessionInterface->OnJoinSessionCompleteDelegates.AddUObject(this, &UMainGameInstance::OnJoinSessionComplete);
			//CreateSession(TEXT("Test Session"));
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Unable to find SessionInterface"))
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Unable to find Online Subsystem"))
	}
}

void UMainGameInstance::CreateSession(FName SessionName)
{
	UE_LOG(LogTemp, Warning, TEXT("Creating Session"))
	if (SessionInterface.IsValid())
	{
		FOnlineSessionSettings SessionSettings;
		SessionSettings.bIsLANMatch = true;
		SessionSettings.NumPublicConnections = 3;
		SessionSettings.bShouldAdvertise = true;
		SessionInterface->CreateSession(0, SessionName, SessionSettings);
	}
}

void UMainGameInstance::OnCreateSessionComplete(FName SessionName, bool bSuccess)
{
	if (bSuccess)
	{
		UE_LOG(LogTemp, Warning, TEXT("Session Created Successfully"))
		// Client travel to the MultiplayerMap
		if (APlayerController* PlayerController = GetPrimaryPlayerController())
		{
			//Change player input back before travelling.
			FInputModeGameOnly InputMode;
			//InputMode.SetWidgetToFocus(Menu->TakeWidget());
			//InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::LockAlways);
			PlayerController->bShowMouseCursor = false;
			PlayerController->SetInputMode(InputMode);
			UWorld* World = GetWorld();
			if (World)
			{
				World->ServerTravel(TEXT("/Game/Levels/MultiplayerMap?listen"));
			}
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Session was not Created"))
		// Destroy the session with this name.
		DestroySession(SessionName);
	}
}

void UMainGameInstance::DestroySession(FName SessionName)
{
	if (SessionInterface.IsValid())
	{
		SessionInterface->DestroySession(SessionName);
	}
}

void UMainGameInstance::OnDestroySessionComplete(FName SessionName, bool bSuccess)
{
	if (bSuccess)
	{
		// If it is successfully destroyed then attempt to create a new session with the same name.
		CreateSession(SessionName);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Unable to destroy session"))
	}
}

void UMainGameInstance::FindSession(FName SessionName)
{
	UE_LOG(LogTemp, Warning, TEXT("Finding Session %s"), *SessionName.ToString())
	SessionSearch = MakeShareable<FOnlineSessionSearch>(new FOnlineSessionSearch());
	if (SessionSearch.IsValid() && SessionInterface.IsValid())
	{
		SessionSearch->bIsLanQuery = true;
		SessionInterface->FindSessions(0, SessionSearch.ToSharedRef());
	}
}

void UMainGameInstance::OnFindSessionComplete(bool bSuccess)
{
	if (bSuccess && SessionSearch.IsValid())
	{
		TArray<FOnlineSessionSearchResult> SearchResults = SessionSearch->SearchResults;
		UE_LOG(LogTemp, Warning, TEXT("Found %i sessions"), SearchResults.Num())
		FName SessionFoundName = "";
		for (const FOnlineSessionSearchResult& SearchResult : SearchResults)
		{
			UE_LOG(LogTemp, Warning, TEXT("Found Session %s"), *SearchResult.GetSessionIdStr())
			SessionFoundName = FName(*SearchResult.GetSessionIdStr());
		}
		JoinSession(SessionFoundName);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Find Sessions was not successful"))
	}
}


void UMainGameInstance::JoinSession(FName SessionName)
{
	UE_LOG(LogTemp, Warning, TEXT("Attempting to join session: %s"), *SessionName.ToString())
	if (SessionInterface.IsValid() && SessionSearch.IsValid() && SessionSearch->SearchResults.Num() > 0)
	{
		SessionInterface->JoinSession(0, SessionName, SessionSearch->SearchResults[0]);
	}
}

void UMainGameInstance::OnJoinSessionComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Result)
{
	if (SessionInterface.IsValid())
	{
		FString Address;
		SessionInterface->GetResolvedConnectString(SessionName, Address);
		APlayerController* PlayerController = GetFirstLocalPlayerController();
		if (PlayerController)
		{
			FInputModeGameOnly InputMode;
			PlayerController->SetInputMode(InputMode);
			PlayerController->ClientTravel(Address, ETravelType::TRAVEL_Absolute);
		}
	}
}
