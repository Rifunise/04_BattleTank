// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerConroller.h"
#include "BattleTank.h"


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
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possessing: %s"), *(ControlledTank->GetName() ));
	}
}

ATank* ATankPlayerConroller::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

