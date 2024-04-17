// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaselinePickup.h"
#include "LighterPickup.generated.h"

/**
 * 
 */
UCLASS()
class GAMEDEVGRP10_API ULighterPickup : public UBaselinePickup
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;

	void StopUse();

	AActor* Player;
};
