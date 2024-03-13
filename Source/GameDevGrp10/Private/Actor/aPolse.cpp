// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/aPolse.h"

// Sets default values
AaPolse::AaPolse()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AaPolse::BeginCooking(bool uncookedState)
{
	GetWorld()->GetTimerManager().SetTimer(CookingDelayTimerHandle, this, &AaPolse::ChangeState, 30.0f, false);
}

// Called when the game starts or when spawned
void AaPolse::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AaPolse::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

