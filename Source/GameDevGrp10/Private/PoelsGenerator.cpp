// Fill out your copyright notice in the Description page of Project Settings.


#include "PoelsGenerator.h"

// Sets default values
APoelsGenerator::APoelsGenerator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APoelsGenerator::BeginPlay()
{
	Super::BeginPlay();

	
}
//These functions create a time frame in which you cannot grab another Poelse
void APoelsGenerator::PoelseGrabbed()
{
	bCanTakePoelse = false;

	GetWorld()->GetTimerManager().SetTimer(
		TakePolsHandle,
		this,
		&APoelsGenerator::PoelseGrabCooldown,
		PoelsTimer,
		false
	);
}

void APoelsGenerator::PoelseGrabCooldown()
{
	bCanTakePoelse = true;
}

