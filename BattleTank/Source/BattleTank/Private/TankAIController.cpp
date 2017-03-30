// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
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

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}


