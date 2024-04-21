// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnemyCharacterBase.generated.h"

UCLASS()
class GAMEDEVGRP10_API AEnemyCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemyCharacterBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EnemyAttribute")
	float DeathTimer = 5.0f;

	/*
	 *	Sound
	 */

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "EnemySound")
	class USoundBase* WalkNoise;
	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "EnemySound")
	class USoundBase* StealNoise;
	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "EnemySound")
	class USoundBase* DeathNoise;

	/*
	 *	Functions
	 */	

	UFUNCTION(BlueprintCallable)
	void EnemyDie();

	UFUNCTION(BlueprintCallable)
	void EnemySteal();

private:
	bool bEnemyDead = false;
	AActor* Player;
	FTimerHandle StopDie;

	void EnemyRemove();

};
