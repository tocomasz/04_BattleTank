// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "Engine.h"
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
	ATank* GetControlledTank() const;
	ATankPlayerController();
	
	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:
	//Start the tank moving the barrel
	void AimTowardsCrosshair();

	//return an OUT parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;
	FHitResult GetFirstPhysicsBodyInReach();

	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5;

	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.33333;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	
};
