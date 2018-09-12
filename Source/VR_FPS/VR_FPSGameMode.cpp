// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "VR_FPSGameMode.h"
#include "VR_FPSHUD.h"
#include "VR_FPSCharacter.h"
#include "UObject/ConstructorHelpers.h"

AVR_FPSGameMode::AVR_FPSGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AVR_FPSHUD::StaticClass();
}
