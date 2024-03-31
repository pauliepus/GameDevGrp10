// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PoelsGenerator.generated.h"

UCLASS()
class APoelsGenerator : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APoelsGenerator();

	/**
	 * Timer part
	 */

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawner")
	float GrabDelay;
	
	FTimerHandle PoelsGrabTimer;

	//int GrabPoelseActor;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	

};
