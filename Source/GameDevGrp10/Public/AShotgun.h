// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AShotgun.generated.h"

UCLASS()
class GAMEDEVGRP10_API AAShotgun : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAShotgun();

	//Mesh call
	UFUNCTION(BlueprintPure, Category="Weapon")
	FORCEINLINE class USkeletalMeshComponent* GetShotgunMesh() const { return Shotgun_Mesh; }
	
	//primary fire thing
	void Fire(const FInputActionValue& Value);
	//just another fire thing
	void Fire2();

	//allowing access
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Projectile")
	TSubclassOf<AActor> Bullet;

protected:
	//Mesh call
	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	class USkeletalMeshComponent* Shotgun_Mesh;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
