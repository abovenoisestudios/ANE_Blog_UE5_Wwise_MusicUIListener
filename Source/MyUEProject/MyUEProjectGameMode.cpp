// Copyright Epic Games, Inc. All Rights Reserved.

#include "MyUEProjectGameMode.h"
#include "MyUEProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMyUEProjectGameMode::AMyUEProjectGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
