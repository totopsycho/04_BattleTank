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

	//-1 max down movement and +1 max up movement
	void Elevate(float RelativeSpeed);

private:

	UPROPERTY(EditAnywhere, Category = setup)
	float MaxDegreesPerSecond = 5.0f;


	UPROPERTY(EditAnywhere, category = setup)
	float MaxElevationDegrees = 40.0f;


	UPROPERTY(EditAnywhere, category = setup)
	float MinElevationDegrees = 0.0f;
	
	
	
	
	
};
