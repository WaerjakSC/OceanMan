// Fill out your copyright notice in the Description page of Project Settings.

#include "RealOceanManager.h"

// Sets default values
ARealOceanManager::ARealOceanManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARealOceanManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARealOceanManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FVector ARealOceanManager::GetWaveHeightValue(FVector location, float time)
{
	FVector sum = FVector(0, 0, 0);

	sum += CalculateGerstnerWaveCluster(2500, 200, FVector2D(location.X, location.Y), FVector2D(0, 1), 0.5f, time);
	sum += CalculateGerstnerWaveCluster(1000, 115, FVector2D(location.X, location.Y), FVector2D(0, 1), 0.5f, time);

	return sum / 2;
}

FVector ARealOceanManager::CalculateGerstnerWaveCluster(float medianWaveLength, float medianAmplitude, FVector2D position, FVector2D medianDirection, float steepness, float time)
{
	FVector sum = FVector(0, 0, 0);

	sum += CalculateGerstnerWave(medianWaveLength, medianAmplitude, position, medianDirection, 0, steepness, time, 0);
	sum += CalculateGerstnerWave(medianWaveLength * 0.5f, medianAmplitude * 0.5f, position, medianDirection, -0.1f, steepness, time, 0);
	sum += CalculateGerstnerWave(medianWaveLength * 2.0f, medianAmplitude * 2.0f, position, medianDirection, 0.1f, steepness, time, 0);
	sum += CalculateGerstnerWave(medianWaveLength * 1.25f, medianAmplitude * 1.25f, position, medianDirection, 0.05f, steepness, time, 0);
	sum += CalculateGerstnerWave(medianWaveLength * 0.75f, medianAmplitude * 0.75f, position, medianDirection, 0.075f, steepness, time, 0);
	sum += CalculateGerstnerWave(medianWaveLength * 1.5f, medianAmplitude * 1.5f, position, medianDirection, -0.125f, steepness, time, 0);
	sum += CalculateGerstnerWave(medianWaveLength * 0.825f, medianAmplitude * 0.825f, position, medianDirection, 0.063f, steepness, time, 0);
	sum += CalculateGerstnerWave(medianWaveLength * 0.65f, medianAmplitude * 0.65f, position, medianDirection, -0.11f, steepness, time, 0);

	return sum / 8;
}

FVector ARealOceanManager::CalculateGerstnerWave(float wavelength, float amplitude, FVector2D position, FVector2D direction, float angle, float steepness, float time, float phase)
{
	float lambda = (2 * PI) / wavelength;

	FVector dir = FVector(direction.X, direction.Y, 0);
	dir = dir.RotateAngleAxis(angle * 360, FVector(0, 0, 1));

	FVector2D rotatedDirection = FVector2D(dir.X, dir.Y);

	float wavePhase = lambda * FVector2D::DotProduct(rotatedDirection, position) * (time + phase);

	float c = FMath::Cos(wavePhase);
	float s = FMath::Sin(wavePhase);

	float QA = steepness * amplitude;

	return FVector(QA * rotatedDirection.X * c, QA * rotatedDirection.Y * c, amplitude * s);
}