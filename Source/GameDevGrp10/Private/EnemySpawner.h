// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Enemy/EnemyBaseCharacter.h"
#include "EnemyBase.h"
#include "EnemySpawner.generated.h"


UCLASS()
class AEnemySpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemySpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(EditAnywhere)
	float SpawnTimer = 5.0f;
	UPROPERTY(EditAnywhere, Category = "Enemy")
	TSubclassOf<AEnemyBaseCharacter> EnemyClass;
	UFUNCTION()
	void SpawnEnemy();
	UFUNCTION()
	void StartSpawning();
	UFUNCTION()
	void StopSpawning();

	FTimerHandle WavePause;
};
