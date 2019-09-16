// Fill out your copyright notice in the Description page of Project Settings.


#include "OceanController.h"
#include "GameFramework/CharacterMovementComponent.h"
AOceanController::AOceanController() : APlayerController()
{

}
void AOceanController::BeginPlay() {
	Super::BeginPlay();
	playerCharacter = Cast<AOceanManCharacter>(GetCharacter());
}

