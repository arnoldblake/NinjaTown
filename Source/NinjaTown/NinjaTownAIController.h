// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "NinjaTownAIController.generated.h"

/**
 * 
 */

class ATargetPoint;

UCLASS()
class NINJATOWN_API ANinjaTownAIController : public AAIController
{
	GENERATED_BODY()

public:
	ANinjaTownAIController();
	void BeginPlay() override;
	void OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result) override;

	UPROPERTY()
		bool Running;

private:
	UPROPERTY()
		TArray<AActor*> Waypoints;
	UFUNCTION()
		ATargetPoint* GetRandomWaypoint();
	UFUNCTION()
		void GoToRandomWaypoint();	
	UFUNCTION()
		void GoToNextWaypoint();
	UPROPERTY()
		int Waypoint;
	FTimerHandle TimerHandle;
};
