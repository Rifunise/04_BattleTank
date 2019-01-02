// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "BattleTank.h"

/*
	Finds the human controlled pawn, casts it to a tank and returns it
*/
ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr;  }
	return Cast<ATank>(PlayerPawn);
}// end GetPlayerTank

/*
	The AI tank(s) attempt to find the human controlled tank and return it's name.
*/
void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Could not find player tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player is currently in tank: %s"), *(PlayerTank->GetName() ));
	}
}//end BeginPlay

/*
	Returns the AI controlled tank
*/
ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}//end GetControlledTank
