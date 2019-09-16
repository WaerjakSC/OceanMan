// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "OceanManCharacter.h"
#include "OceanController.generated.h"

/**
 * 
 */
UCLASS()
class OCEANMAN_API AOceanController : public APlayerController
{
	GENERATED_BODY()
public:
	// Sets default values for this pawn's properties
	AOceanController();

	void BeginPlay() override;
	void switchControlledObject();

	UPROPERTY(EditAnywhere)
	APawn *ship;
private:
	UPROPERTY(EditAnywhere)
		AOceanManCharacter *playerCharacter;
protected:

};
