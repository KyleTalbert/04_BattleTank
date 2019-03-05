// Fill out your copyright notice in the Description page of Project Settings.

#include "Engine/World.h"
#include "TankAIController.h"

void ATankAIController::Tick(float Deltatime)
{
	Super::Tick(Deltatime);
	if (GetPlayerTank()) 
	{
		// Move towards player

		// Aim towards player
		GetAIControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

		// Fire when ready
	}
	
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto AIControlledTank = GetAIControlledTank();
	if (!AIControlledTank)
	{
		UE_LOG(LogTemp, Error, TEXT("AI did not possess tank."));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI possessed pawn: %s"), *AIControlledTank->GetName());
	}

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Error, TEXT("AI cant find Player tank."));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI found %s"), *PlayerTank->GetName());
	}
}

ATank* ATankAIController::GetAIControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);
}