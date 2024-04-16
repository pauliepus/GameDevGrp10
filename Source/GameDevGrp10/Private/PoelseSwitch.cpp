// Fill out your copyright notice in the Description page of Project Settings.


#include "PoelseSwitch.h"

// Sets default values
APoelseSwitch::APoelseSwitch()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APoelseSwitch::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APoelseSwitch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APoelseSwitch::Interact_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, TEXT("Interacted!!! Wow!"));
}