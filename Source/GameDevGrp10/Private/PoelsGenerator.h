// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PoelsGenerator.generated.h"

/*
 * Spawner based on: https://youtu.be/8KWZQjMFcdE
 *
 * Timer based on : https://youtu.be/023iYtHpBFc
 */

UCLASS()
class APoelsGenerator : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APoelsGenerator();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Timer")
	int PoelsTimer;

	FTimerHandle TakePolsHandle;
};
