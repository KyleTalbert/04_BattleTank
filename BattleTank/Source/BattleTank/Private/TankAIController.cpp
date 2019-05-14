// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "Tank.h"
#include "Engine/World.h"

void ATankAIController::Tick(float Deltatime)
{
	Super::Tick(Deltatime);

	auto PlayerPawn = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto AIControlledTank = Cast<ATank>(GetPawn());

	if (PlayerPawn) 
	{
		// Move towards player

		// Aim towards player
		AIControlledTank->AimAt(PlayerPawn->GetActorLocation());

		AIControlledTank->Fire();
	}
	
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

}

