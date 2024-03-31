// Fill out your copyright notice in the Description page of Project Settings.


#include "PoelsGenerator.h"

// Sets default values
APoelsGenerator::APoelsGenerator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//This part, along with the files in the header are referenced from https://youtu.be/023iYtHpBFc

	GrabDelay = 8.0f;

}

// Called when the game starts or when spawned
void APoelsGenerator::BeginPlay()
{
	Super::BeginPlay();

	GrabDelay;

	GetWorld()->GetTimerManager().SetTimer(FTimerHandle PoelsGrabTimer, this, APoelsGenerator::GrabPoelseActor, GrabDelay, false);

}

/*
 *spawner functionality based on https://youtu.be/7H08G1sPNj8
 */

