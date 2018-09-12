// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "VR_FPSHUD.generated.h"

UCLASS()
class AVR_FPSHUD : public AHUD
{
	GENERATED_BODY()

public:
	AVR_FPSHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

