// Fill out your copyright notice in the Description page of Project Settings.


#include "LighterPickup.h"
#include "PlayerCharacter.h"
#include "Kismet/GameplayStatics.h"

void ULighterPickup::BeginPlay()
{
	Super::BeginPlay();
	Player = UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetPawn();
}

void ULighterPickup::StopUse()
{
	APlayerCharacter* PlayerCharacter = Cast<APlayerCharacter>(Player);
	PlayerCharacter->EndWave();
}
