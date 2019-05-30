// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NinjaTownExtractionZone.generated.h"

class UBoxComponent;

UCLASS()
class NINJATOWN_API ANinjaTownExtractionZone : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANinjaTownExtractionZone();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void HandleOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UPROPERTY(VisibleAnywhere, Category = Components)
	UBoxComponent* BoxComponent;

	UPROPERTY(VisibleAnywhere, Category = Components)
	UDecalComponent* DecalComponent;

	UPROPERTY(EditDefaultsOnly, Category = Sounds)
	USoundBase* ObjectiveMissingSound;

public:	

};
