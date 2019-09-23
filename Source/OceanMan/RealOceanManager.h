// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RealOceanManager.generated.h"

UCLASS()
class OCEANMAN_API ARealOceanManager : public AActor
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category = "OceanManager|Ocean Manager")
	FVector GetWaveHeightValue(FVector location, float time);

	FVector CalculateGerstnerWaveCluster(float medianWaveLength, float medianAmplitude, FVector2D position, FVector2D medianDirection, float steepness, float time);
	FVector CalculateGerstnerWave(float wavelength, float amplitude, FVector2D position, FVector2D direction, float angle, float steepness, float time, float phase);

public:	
	// Sets default values for this actor's properties
	ARealOceanManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
