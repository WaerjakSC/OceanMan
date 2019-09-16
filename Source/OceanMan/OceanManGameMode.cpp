// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "OceanManGameMode.h"
#include "OceanManCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "OceanController.h"
AOceanManGameMode::AOceanManGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<AOceanManCharacter> PlayerPawnBPClass(TEXT("/Game/Blueprints/Player/BP_OceanManCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
	PlayerControllerClass = AOceanController::StaticClass();
}
