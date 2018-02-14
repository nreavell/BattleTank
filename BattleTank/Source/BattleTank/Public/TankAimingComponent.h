// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "Components/StaticMeshComponent.h"
#include "TankAimingComponent.generated.h"

UENUM()
enum class EFiringState : uint8
{
	Reloading,
	Aiming,
	Locked
};

class UTankBarrel; //Forward Declaration
class UTankTurret;
class AProjectile;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringState FiringState = EFiringState::Reloading;


public:	

	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialise(UTankTurret* TurretToSet, UTankBarrel* BarrelToSet);

	UFUNCTION(BlueprintCallable, Category = "Firing")
	void Fire();

	bool IsBarrelMoving();
		
private:

	UTankBarrel*  Barrel =  nullptr;

	UTankTurret* Turret = nullptr;

	void MoveBarrelTowards(FVector AimDirection);

	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float LaunchSpeed = 4000.f;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float ReloadTimeInSeconds = 3.f;

	double LastFireTime = 0;

	FVector AimDirection;
};
