// Fill out your copyright notice in the Description page of Project Settings.


#include "PickUpBasePoels.h"

#include "NavigationSystemTypes.h"


// Sets default values
APickUpBasePoels::APickUpBasePoels()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bIsActive = true;

	//pickup part
	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Pickup Mesh"));
	RootComponent = PickupMesh;
}

bool APickUpBasePoels::bIsPickupActive() const
{
	return bIsActive;
}

void APickUpBasePoels::SetPickupIsActive(bool NewActiveState)
{
	bIsActive = NewActiveState;
}

// Called when the game starts or when spawned
void APickUpBasePoels::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APickUpBasePoels::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

