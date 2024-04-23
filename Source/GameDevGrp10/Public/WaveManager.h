// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemySpawner.h"
#include "LevelSequence.h"
#include "LevelSequencePlayer.h"
#include "PlayerCharacter.h"

#include "WaveManager.generated.h"


UCLASS()
class GAMEDEVGRP10_API AWaveManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWaveManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/*
	 *Waves
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound")
	USoundBase* WindSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WaveOptions")
	int WaveTimer = 180;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WaveOptions")
	int WaveNumber = 0;	

	UFUNCTION()
	void WaveStart();

	UFUNCTION(BlueprintCallable)
	void WaveEnd();

	

	/*
	 *Timer
	 */

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wave Timer")
	int Seconds;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wave Timer")
	int32 Minutes;

	/*
	 *Troll Animation
	 *This is based on the discussion from this page https://forums.unrealengine.com/t/is-there-a-way-to-trigger-a-level-sequence-in-c/381446/8
	 */
	
	UFUNCTION()
	void TrollAnimDone();
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "TrollAnim")
	ULevelSequence* TrollSequence;
	
	ALevelSequenceActor* TrollSequenceActor;
	
	ULevelSequencePlayer* TrollSequencePlayer;
	FTimerHandle StopTroll;

	
public:
	FTimerHandle PauseWave;
	FTimerHandle T_CountDown;
	void CountDown();
	bool ManagerWaveEnded = false;
	float EndWaveDelay = 7.0f;

	AEnemySpawner* TargetSpawner;
	APlayerCharacter* Player;
};
