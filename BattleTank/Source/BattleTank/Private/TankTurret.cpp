// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"
#include "Engine/World.h"


void UTankTurret::Turn(float RelativeSpeed) {
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);
	auto TurnChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto TurnRotation = RelativeRotation.Yaw + TurnChange;

	SetRelativeRotation(FRotator(0, TurnRotation, 0));
}

