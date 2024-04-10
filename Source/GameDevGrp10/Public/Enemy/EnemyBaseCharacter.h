// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnemyBaseCharacter.generated.h"

UCLASS()
class GAMEDEVGRP10_API AEnemyBaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemyBaseCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	/*
	 *	Sound
	 */
	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "EnemySound")
	class USoundBase* EnemyNoise;
	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "EnemySound")
	class USoundBase* EnemySteal;
	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "EnemySound")
	class USoundBase* EnemyDeath;

	/*
	 *	Functions
	 */
	bool bEnemyDead = false;
	FTimerHandle StopDie;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EnemyAttribtue")
	float DeathTimer = 5.0f;

	bool bHasTarget = false;
	float fTargetDistance;


	AActor* Player;



	UFUNCTION()
	void EnemyDie();
};
