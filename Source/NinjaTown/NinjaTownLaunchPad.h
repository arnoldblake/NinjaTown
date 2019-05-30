// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NinjaTownLaunchPad.generated.h"

class UBoxComponent;

UCLASS()
class NINJATOWN_API ANinjaTownLaunchPad : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANinjaTownLaunchPad();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category = Components)
	UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY(VisibleAnywhere, Category = Components)
	UBoxComponent* BoxComponent;

	UPROPERTY(EditAnywhere, Category = LaunchVelocity)
	FVector LaunchVector;

public:
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
};
