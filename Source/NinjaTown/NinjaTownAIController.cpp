// Fill out your copyright notice in the Description page of Project Settings.


#include "NinjaTownAIController.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/TargetPoint.h"
#include "TimerManager.h"

ANinjaTownAIController::ANinjaTownAIController()
{
	Waypoint = 0;
	Running = true;
}

void ANinjaTownAIController::BeginPlay()
{
	Super::BeginPlay();
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATargetPoint::StaticClass(), Waypoints);
	//GoToRandomWaypoint();
	//GoToNextWaypoint();
}

void ANinjaTownAIController::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult & Result)
{
	Super::OnMoveCompleted(RequestID, Result);
	if (Running)
	{
		//GetWorldTimerManager().SetTimer(TimerHandle, this, &ANinjaTownAIController::GoToRandomWaypoint, 1.0f, false);
		//GetWorldTimerManager().SetTimer(TimerHandle, this, &ANinjaTownAIController::GoToNextWaypoint, 1.0f, false);
	}
}

ATargetPoint * ANinjaTownAIController::GetRandomWaypoint()
{
	int Waypoint = FMath::RandRange(0, Waypoints.Num() - 1);
	return Cast<ATargetPoint>(Waypoints[Waypoint]);
}

void ANinjaTownAIController::GoToRandomWaypoint()
{
	MoveToActor(GetRandomWaypoint());
}

void ANinjaTownAIController::GoToNextWaypoint()
{
	// Are we at the last waypoint?
	if (Waypoint >= Waypoints.Num() - 1)
	{
		Waypoint = 0;
	}
	else
	{
		Waypoint++;
	}
	MoveToActor(Cast<ATargetPoint>(Waypoints[Waypoint]));
}
