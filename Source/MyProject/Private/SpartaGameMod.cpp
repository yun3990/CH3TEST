// Fill out your copyright notice in the Description page of Project Settings.

#include "MyPawn.h"
#include "SpartaGameMod.h"
#include "SpartaCharacter.h"
#include "SpartaPlayerController.h"

ASpartaGameMod::ASpartaGameMod()
{
	DefaultPawnClass = AMyPawn::StaticClass();
	PlayerControllerClass = ASpartaPlayerController::StaticClass();
}