// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "NinjaTownGameMode.h"
#include "NinjaTownHUD.h"
#include "NinjaTownCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"

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
		if (SpectatingViewpointClass)
		{
			TArray<AActor*> OutActors;
			UGameplayStatics::GetAllActorsOfClass(this, SpectatingViewpointClass, OutActors);

			if (OutActors.Num() > 0)
			{
				AActor* NewViewTarget = OutActors[0];

				APlayerController* PlayerController = Cast<APlayerController>(InstigatorPawn->GetController());
				if (PlayerController)
				{
					PlayerController->SetViewTargetWithBlend(NewViewTarget, 0.5f, EViewTargetBlendFunction::VTBlend_Cubic);
				}
			}
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("SpectatingViewpointClass is nullptr. Cannot change view target."));
		}
	}

	OnMissionCompleted(InstigatorPawn);
}
