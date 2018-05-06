// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "Engine/World.h"
#include"Kismet/GameplayStatics.h"
#include "Components/StaticMeshComponent.h"



// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	Barrel = BarrelToSet;
}



void UTankAimingComponent::AimAt(FVector OutHitLocation, float LaunchSpeed)
{
	if (!Barrel) { return; }

	FVector OutLauchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));

	if (UGameplayStatics::SuggestProjectileVelocity
			(
		this,
		OutLauchVelocity,
		StartLocation,
		OutHitLocation,
		LaunchSpeed,
		false,
		0.0f,
		0.0f,
		ESuggestProjVelocityTraceOption::DoNotTrace
			)
		)

		{
			auto AimDirection = OutLauchVelocity.GetSafeNormal();
			UE_LOG(LogTemp, Warning, TEXT("Aiming at %s"),*AimDirection.ToString());
			MoveBarrelTowards(AimDirection);
			auto Time = GetWorld()->GetTimeSeconds();
			UE_LOG(LogTemp, Warning, TEXT("%f : Elevate is working"), Time)

		}
	else
	{
		auto Time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("%f : no solution found"), Time)
	}
		
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	
	// Work-out the difference between the current barrel rotation and the aim direction
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = BarrelRotator - AimAsRotator;
	Barrel->Elevate(DeltaRotator.Pitch);
}

	
	

