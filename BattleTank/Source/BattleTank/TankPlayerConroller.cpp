// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerConroller.h"
#include "BattleTank.h"

/*
	returns the name of the human controlled tank if found
*/
void ATankPlayerConroller::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possessing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possessing: %s"), *(ControlledTank->GetName()));
	}
}//end BeginPlay

// Called every frame
void ATankPlayerConroller::Tick(float DeltaTime)
{
	Super::Tick( DeltaTime );
	AimTowardsCrosshair();

}//end Tick


/*
	Returns the human controlled tank
*/
ATank* ATankPlayerConroller::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}//end GetControlledTank

void ATankPlayerConroller::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation; // Out parameter
	if (GetSightRayHitLocation(HitLocation)) //Has "side-effect", is going to line trace
	{
		UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *HitLocation.ToString());
			//TODO Tell controlled tank to aim at this point
	}
}

// Get world location of linetrace through crosshair, true if it hits landscape
bool ATankPlayerConroller::GetSightRayHitLocation(FVector& HitLocation) const
{
	HitLocation = FVector(1.0);
	return true;
}

