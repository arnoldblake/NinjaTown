// Fill out your copyright notice in the Description page of Project Settings.


#include "NinjaTownBlackHole.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ANinjaTownBlackHole::ANinjaTownBlackHole()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	StaticMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	RootComponent = StaticMeshComponent;


	InnerSphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("InnerSphereComponent"));
	InnerSphereComponent->SetSphereRadius(100);
	InnerSphereComponent->SetupAttachment(StaticMeshComponent);


	OuterSphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("OuterSphereComponent"));
	OuterSphereComponent->SetSphereRadius(3000);
	OuterSphereComponent->SetupAttachment(StaticMeshComponent);

}

// Called when the game starts or when spawned
void ANinjaTownBlackHole::BeginPlay()
{
	Super::BeginPlay();
	InnerSphereComponent->OnComponentBeginOverlap.AddDynamic(this, &ANinjaTownBlackHole::OverlapInnerSphere);
	
}

void ANinjaTownBlackHole::OverlapInnerSphere(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor)
	{
		OtherActor->Destroy();
	}
}

// Called every frame
void ANinjaTownBlackHole::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TArray<UPrimitiveComponent *> OverlappingComponents;	
	OuterSphereComponent->GetOverlappingComponents(OverlappingComponents);

	for (int32 i = 0; i < OverlappingComponents.Num(); i++)
	{
		UPrimitiveComponent* PrimitiveComponent;
		PrimitiveComponent = OverlappingComponents[i];

		if (PrimitiveComponent && PrimitiveComponent->IsSimulatingPhysics())
		{
			const float Radius = OuterSphereComponent->GetScaledSphereRadius();
			const float Strength = -2000;
			PrimitiveComponent->AddRadialForce(GetActorLocation(), Radius, Strength, ERadialImpulseFalloff::RIF_Constant, true);
		}
	}

}

