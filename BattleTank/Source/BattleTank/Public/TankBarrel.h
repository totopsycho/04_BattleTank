// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()

public:

	void Elevate(float RelativeSpeed, float MaxDegreesElevation, float MinDegreesElevation);

private:

	UPROPERTY(EditAnywhere)
	float MaxDegreesPerSecond = 20.0f;


	UPROPERTY(EditAnywhere)
		float MaxDegreesElevation = 45.0f;


	UPROPERTY(EditAnywhere)
		float MinDegreesElevation = -10.0f;
	
	
	
	
	
};
