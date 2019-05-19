// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "NinjaTownHUD.generated.h"

UCLASS()
class ANinjaTownHUD : public AHUD
{
	GENERATED_BODY()

public:
	ANinjaTownHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

