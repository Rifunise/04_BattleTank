// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerConroller.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerConroller : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void Tick(float DeltaTime) override;

private:
	ATank* GetControlledTank() const;

	virtual void BeginPlay() override;

	//Start the tank moving the barrel so that a shot would hit where the
	//crosshair intersects the world
	void AimTowardsCrosshair();
	bool GetSightRayHitLocation(FVector& HitLocation) const;
};
