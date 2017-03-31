// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	ATank* PlayerTank = GetPlayerTank();

	if (PlayerTank != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player TANK with ID: %s"), *PlayerTank->GetName())

	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No Player TANK"))
	}

}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ATank* PlayerTank = GetPlayerTank();
	if (GetPlayerTank())
	{
		GetControlledTank()->AimAt(PlayerTank->GetActorLocation());
	}
	
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}


