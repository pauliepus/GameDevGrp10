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
	class UStaticMeshComponent* EnemyMesh;
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
	float Speed = 5.0f;
	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "EnemyAttribute")
	float Health = 1.0f;
	
	bool bEnemyDead = false;
	bool bHasTarget = false;
	float fTargetDistance;

	AActor* Player;


	UFUNCTION()
	void EnemyTarget(AActor* target);
};
