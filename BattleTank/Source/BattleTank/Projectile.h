// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Projectile.generated.h"


class UProjectileMovementComponent;
UCLASS()
class BATTLETANK_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;



public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void LaunchProjectile(float Speed);

private:
	UProjectileMovementComponent* ProjectileMovement = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Component")
	UStaticMeshComponent* CollisionMesh = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Component")
	UParticleSystemComponent* LaunchBlast = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Component")
	UParticleSystemComponent* ImpactBlast = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float DestroyDelay = 10.0;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float ProjectileDamage = 20.f;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

	void OnTimerExpires();

	UPROPERTY(VisibleAnywhere, Category = "Component")
	URadialForceComponent* ExplosionForce = nullptr;
	
	
};
