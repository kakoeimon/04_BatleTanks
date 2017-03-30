// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"




void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Tank Player Controller Begin Play"));
	ATank* ControlledTank = GetControlledTank();
	if (ControlledTank)
	{
		UE_LOG(LogTemp, Error, TEXT("You posses a tank and it's name is %s"), *ControlledTank->GetName())
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("You do not posses a tank"))
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
	AimTowardsCrosshair();
}


ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }
	FVector HitLocation;

	if ( GetSightRayHitLocation(HitLocation) )
	{
		UE_LOG(LogTemp, Error, TEXT("HitLocation: %s"), *HitLocation.ToString());
	}
	return;
}

bool ATankPlayerController::GetSightRayHitLocation(FVector & HitLocation) const
{
	HitLocation = FVector(10.0f, 10.0f, 10.0f);
	int32 view_x, view_y;
	GetViewportSize(view_x, view_y);
	FVector2D CrossPos = FVector2D(view_x / 2.f, view_y / 3.f);
	FHitResult HitResult;
	bool bHit = GetHitResultAtScreenPosition(CrossPos, ECollisionChannel::ECC_WorldStatic, false, HitResult);
	if (bHit)
	{
		HitLocation = HitResult.ImpactPoint;
		return true;
	}
	return false;
}

