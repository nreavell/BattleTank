// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

// Forward declarations

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, class AController * EventInstigator, AActor* DamageCauser) override;

	UFUNCTION(BlueprintPure, Category = "Health")
	float GetHealthPercent();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	
private:	

	UPROPERTY(EditDefaultsOnly, Category = "Health")
	int32 MaxHealth = 100;

	UPROPERTY(EditAnywhere, Category = "Health")
	int32 CurrentHealth = 100;
};
