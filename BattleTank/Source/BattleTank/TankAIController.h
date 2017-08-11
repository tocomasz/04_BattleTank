// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "Engine.h"
#include "AIController.h"
#include "TankAIController.generated.h"

class UTankAimingComponent;

UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

protected:

	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
	void FoundAimingComponent(UTankAimingComponent* AimingCompRef);


	UPROPERTY(BlueprintReadOnly)
	UTankAimingComponent* AimingComponent = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float AcceptanceRadius = 80000;

private:
	ATankAIController();

	virtual void SetPawn(APawn* InPawn) override;
	
	void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnPossessedTankDeath();



	
};
