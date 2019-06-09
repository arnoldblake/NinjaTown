// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "NinjaTownAIGuard.generated.h"

UENUM(BlueprintType)
enum class EAIState : uint8
{
	Idle,
	Suspicious,
	Alerted
};

UCLASS()
class NINJATOWN_API ANinjaTownAIGuard : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ANinjaTownAIGuard();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnPawnSeen(APawn* SeenPawn);

	UFUNCTION()
	void OnNoiseHeard(APawn* NoiseInstigator, const FVector& Location, float Volume);

	UFUNCTION()
	void ResetOrientation();

	void SetGuardState(EAIState NewState);

	UFUNCTION(BlueprintImplementableEvent, Category = AI)
	void OnStateChanged(EAIState NewState);

	UPROPERTY(VisibleAnywhere, Category = Component)
	class UPawnSensingComponent* PawnSensingComponent;

	FTimerHandle TimerHandle;
	FRotator OriginalRotation;

	EAIState GuardState;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
