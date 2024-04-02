// Fill out your copyright notice in the Description page of Project Settings.


#include "PickUpBasePoels.h"

#include "NavigationSystemTypes.h"

/*
 * Pickup based on https://youtu.be/cBnYYois1vM 
 */

// Sets default values
APickUpBasePoels::APickUpBasePoels()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//this
	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Pickup Mesh"));
	RootComponent = PickupMesh;
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

