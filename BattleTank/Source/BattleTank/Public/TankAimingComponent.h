// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

UENUM()
enum class EFiringState : uint8
{
	Reloading,
	Aiming,
	Locked
};

class UTankBarrel;
class UTankTurret;

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

	UPROPERTY(BlueprintReadOnly, Category = "Status")
	EFiringState FiringStatus = EFiringState::Reloading;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;

	void AimAt(FVector HitLocation, float LaunchSpeed) const;

	UFUNCTION(BlueprintCallable, Category = Setup)
	void Initialise(UTankBarrel* TankBarrelToSet, UTankTurret* TankTurretToSet);

private:

	
	void MoveBarrelTowards(FVector AimDirection) const;
	void RotateTurretTowards(FVector AimDirection) const;

	
	
	
};
