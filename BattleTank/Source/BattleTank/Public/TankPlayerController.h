// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ATank* GetControlledTank() const;
	
	void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	void AimTowardsCrosshair();

private:
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	UPROPERTY(EditAnywhere)
		float CrosshairXLocation = .5;

	UPROPERTY(EditAnywhere)
		float CrosshairYLocation = .3333;
};
