// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:


private:
	//When the game begins
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	ATank * GetControlledTank() const;

	//Start the tank to move the barrel so that a shot would hit
	//where the crosshair intersects the world

	void AimTowardsCrossHair();

	bool GetSightRayHitLocation(FVector& OutHitLocation) const;

	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5f;

	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.3333f;
	
	FVector2D ScreenLocation;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000.f;
	
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& OutHitLocation) const;
	
	
};
