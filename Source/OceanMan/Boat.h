// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WheeledVehicle.h"
#include "Boat.generated.h"

/**
 * 
 */
UCLASS()
class OCEANMAN_API ABoat : public AWheeledVehicle
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mesh")
	class UStaticMeshComponent *boatMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stencil")
	class UStaticMeshComponent *waterStencil;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// UFUNCTION(BlueprintCallable, Category="Ship")
	// void RegisterShipSystem(UShipSystem* ShipSystem);

	// UFUNCTION(BlueprintCallable, Category="Ship|Control")
	// void SetThrottle(float ThrottleAmount);
	// UFUNCTION(BlueprintCallable, Category = "Ship|Control")
	// void SetSteering(float SteeringAmount);

};
