// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Boat.generated.h"

/**
 * 
 */
UCLASS()
class OCEANMAN_API ABoat : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABoat();

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
	class USpringArmComponent *cameraArm;
	/** Follow camera */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
	class UCameraComponent *camera;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Boat")
	UStaticMeshComponent *boatMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
