// Fill out your copyright notice in the Description page of Project Settings.


#include "NinjaTownLaunchPad.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "NinjaTownCharacter.h"

// Sets default values
ANinjaTownLaunchPad::ANinjaTownLaunchPad()
{
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	RootComponent = StaticMeshComponent;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	BoxComponent->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ANinjaTownLaunchPad::BeginPlay()
{
	Super::BeginPlay();
	
}

void ANinjaTownLaunchPad::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	ANinjaTownCharacter* Character = Cast<ANinjaTownCharacter>(OtherActor);
	if (Character)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player colliding with LaunchPad"));
		Character->LaunchCharacter(LaunchVector, false, false);
		UGameplayStatics::SpawnEmitterAtLocation(this, LaunchFX, GetActorLocation());
	}
}