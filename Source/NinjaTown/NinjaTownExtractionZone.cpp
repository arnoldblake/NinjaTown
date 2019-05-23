// Fill out your copyright notice in the Description page of Project Settings.


#include "NinjaTownExtractionZone.h"
#include "Components/BoxComponent.h"

// Sets default values
ANinjaTownExtractionZone::ANinjaTownExtractionZone()
{

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	BoxComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	BoxComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
	BoxComponent->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	BoxComponent->SetBoxExtent(FVector(200.0f));
	RootComponent = BoxComponent;

}

// Called when the game starts or when spawned
void ANinjaTownExtractionZone::BeginPlay()
{
	Super::BeginPlay();

	BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &ANinjaTownExtractionZone::HandleOverlap);
	
}

void ANinjaTownExtractionZone::HandleOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Log, TEXT("Overlap with extraction zone!"));
}

