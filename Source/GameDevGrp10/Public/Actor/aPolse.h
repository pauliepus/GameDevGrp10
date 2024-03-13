// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "aPolse.generated.h"

UCLASS()
class GAMEDEVGRP10_API AaPolse : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AaPolse();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// State confirm, FIRST boolean function
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Polse State")
	bool bUncookedState = true;
	
	// To be able to begin cooking
	UPROPERTY(BlueprintCallable, Category = "Polse State")
	void BeginCooking(bool uncookedState);

	// To change the state
	UPROPERTY(BlueprintCallable, Category = "Polse State")
	void ChangeState;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
