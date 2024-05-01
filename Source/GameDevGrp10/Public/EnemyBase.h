// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemyBase.generated.h"

UCLASS()
class GAMEDEVGRP10_API AEnemyBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemyBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:

	/*
		Enemy Parts
	*/
	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "EnemyAttribute")
	class USkeletalMeshComponent* EnemyMesh;
	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "EnemyAttribute")
	class UShapeComponent* EnemyHitBox;
	

	/*
		Sound
	*/
	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "EnemySound")
	class USoundBase* EnemyNoise;
	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "EnemySound")
	class USoundBase* EnemySteal;
	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "EnemySound")
	class USoundBase* EnemyDeath;

	/*
		Attributes
	*/
	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "EnemyAttribute")
	float Speed = 0.1f;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "EnemyAttribute")
	float Health = 1.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EnemyAttribtue")
	float DeathTimer = 5.0f;

	/*
	 *Functions
	 */
	UFUNCTION()
	void EnemyTarget(AActor* target);
	UFUNCTION()
	void EnemyDie();

private:
	bool bHasTarget = false;
	float fTargetDistance;
	bool bEnemyDead = false;
	FTimerHandle StopDie;
	AActor* Player;
};
