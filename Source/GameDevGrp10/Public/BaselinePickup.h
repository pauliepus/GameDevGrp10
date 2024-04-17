// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractInterface.h"
#include "PlayerCharacter.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/StaticMeshComponent.h"
#include "BaselinePickup.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class GAMEDEVGRP10_API UBaselinePickup : public USkeletalMeshComponent, public IInteractInterface
{
	GENERATED_BODY()

public:

	//attach parts

	UBaselinePickup();

	APlayerCharacter* Character;

	UFUNCTION(Blueprintable, BlueprintCallable, Category = "Object")
	void AttachComponentToPlayer(APlayerCharacter* TargetCharacter);

	UFUNCTION()
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeaponSettings")
	FVector GuntipOffset;


	//Input Actions

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	class UInputMappingContext* ItemIMC;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	class UInputAction* UseAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	class UInputAction* StopUseAction;

	//IMC definitions for InputMappings

	UFUNCTION(BlueprintCallable, Category = "Input")
	void Use();

	UFUNCTION(BlueprintCallable, Category = "Input")
	void StopUse();

	
	UPROPERTY(EditAnywhere, Category="ReSpawn")
	TSubclassOf<AActor> Respawn;



	/*
	 * Sounds
	 */

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Animation And Sound")
	USoundBase* ItemSound;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Animation And Sound")
	UAnimMontage* ItemAnimation;

	/*
	 * Projectile
	 */

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Projectile")
	TSubclassOf<AActor> ProjectileToSpawn;


	virtual void Interact_Implementation(APlayerCharacter* TargetCharacter) override;
};
