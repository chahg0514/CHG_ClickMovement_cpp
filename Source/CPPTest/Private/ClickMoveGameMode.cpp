// Fill out your copyright notice in the Description page of Project Settings.


#include "ClickMoveGameMode.h"
#include "ClickMoveCharacter.h"
#include "ClickMovePlayerController.h"

AClickMoveGameMode::AClickMoveGameMode()
{
	DefaultPawnClass = AClickMoveCharacter::StaticClass();
	PlayerControllerClass = AClickMovePlayerController::StaticClass();

}

