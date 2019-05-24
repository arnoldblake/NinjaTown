// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "NinjaTownGameMode.h"
#include "NinjaTownHUD.h"
#include "NinjaTownCharacter.h"
#include "UObject/ConstructorHelpers.h"

ANinjaTownGameMode::ANinjaTownGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ANinjaTownHUD::StaticClass();
}

void ANinjaTownGameMode::CompleteMission(APawn* InstigatorPawn)
{
	if (InstigatorPawn)
	{
		InstigatorPawn->DisableInput(nullptr);
	}

	OnMissionCompleted(InstigatorPawn);
}
