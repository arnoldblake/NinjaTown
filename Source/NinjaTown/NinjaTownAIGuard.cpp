// Fill out your copyright notice in the Description page of Project Settings.


#include "NinjaTownAIGuard.h"
#include "Perception/PawnSensingComponent.h"
#include "DrawDebugHelpers.h"
#include "TimerManager.h"
#include "NinjaTownGameMode.h"

// Sets default values
ANinjaTownAIGuard::ANinjaTownAIGuard()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PawnSensingComponent = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("PawnSensingComponent"));
}

// Called when the game starts or when spawned
void ANinjaTownAIGuard::BeginPlay()
{
	Super::BeginPlay();

	PawnSensingComponent->OnSeePawn.AddDynamic(this, &ANinjaTownAIGuard::OnPawnSeen);
	PawnSensingComponent->OnHearNoise.AddDynamic(this, &ANinjaTownAIGuard::OnNoiseHeard);

	OriginalRotation = GetActorRotation();
	
}

// Called every frame
void ANinjaTownAIGuard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ANinjaTownAIGuard::OnPawnSeen(APawn* SeenPawn)
{
	if (SeenPawn == nullptr)
	{
		return;
	}
	DrawDebugSphere(GetWorld(), SeenPawn->GetActorLocation(), 32.0f, 12, FColor::Red, false, 10.0f);
	
	ANinjaTownGameMode* GameMode = Cast<ANinjaTownGameMode>(GetWorld()->GetAuthGameMode());
	if (GameMode)
	{
		GameMode->CompleteMission(SeenPawn, false);
	}
}

void ANinjaTownAIGuard::OnNoiseHeard(APawn * NoiseInstigator, const FVector& Location, float Volume)
{
	DrawDebugSphere(GetWorld(), Location, 32.0f, 12, FColor::Green, false, 10.0f);

	FVector Direction = Location - GetActorLocation();
	Direction.Normalize();

	FRotator LookAt = FRotationMatrix::MakeFromX(Direction).Rotator();
	LookAt.Pitch = 0.0f;
	LookAt.Roll = 0.0f;

	SetActorRotation(LookAt);

	GetWorldTimerManager().ClearTimer(TimerHandle);
	GetWorldTimerManager().SetTimer(TimerHandle, this, &ANinjaTownAIGuard::ResetOrientation, 3.0f);
}

void ANinjaTownAIGuard::ResetOrientation()
{
	SetActorRotation(OriginalRotation);
}
