// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/TextureRenderTarget2D.h"
#include "AHeightMapReader.generated.h"


UCLASS()
class OCEANMAN_API AAHeightMapReader : public AActor
{
	GENERATED_BODY()

	UPROPERTY(Category = HeightMap, EditAnywhere)
	UTextureRenderTarget2D* RenderTarget;

	UFUNCTION(BlueprintCallable, Category = "HeightMap|Update")
	void UpdateBuffer();

	UFUNCTION(BlueprintCallable, Category = "HeightMap|Texture Helper")
	FColor GetRenderTargetValue(float x, float y);
	
public:	
	// Sets default values for this actor's properties
	AAHeightMapReader();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	TArray<FColor> ColorBuffer;

};
