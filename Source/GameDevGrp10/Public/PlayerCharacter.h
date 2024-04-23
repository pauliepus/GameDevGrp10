// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

class UInputMappingContext;
class UInputComponent;
struct FInputActionValue;
class UInputAction;
class UCameraComponent;

UCLASS()
class GAMEDEVGRP10_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void GetMeshFPV();

	//Fire Interact Component declaration
	APlayerCharacter* FireCharacter;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* InteractAction;

	UFUNCTION(Category = "Interact")
	void InteractWithObjects(const FInputActionValue& Value);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interact")
	float InteractRange = 500.f;

	//UFUNCTION(Blueprintable, BlueprintCallable, Category = "Object")
	//void AttachComponentToPlayer(APlayerCharacter* TargetCharacter);
	
	
	/*
	* Weapon Bools
	*/
		
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapon")
	bool bHasWeapon = false;

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void SetHasWeapon(bool bHasNewWeapon);

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	bool GetHasWeapon();
	//End

	/*
	* Lighter bools
	*/

	UPROPERTY(BlueprintReadWrite, Category = "Lighter")
	bool bHasLighter;

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void SetHasLighter(bool bHasNewWeapon);

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	bool GetHasLighter();
	//End

	/*
	* Firing part (IA)
	*/

	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category = "Input")
	class UInputAction* FireAction;

	UFUNCTION(Blueprintable, Category = "Input")
	void Fire();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Projectile")
	TSubclassOf<AActor> ProjectileToSpawn;
	//End

	/*
	 * Attributes
	 */

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USkeletalMeshComponent* MeshFPV;
	
		//Camera Component
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	UCameraComponent* PlayerCamera;

	UCameraComponent* GetCameraComponent() const;

	USkeletalMeshComponent* GetMeshFPV() const;
	
	//Camera Look (IA)

	void Look(const FInputActionValue& Value);


	/*
	 * Inputs
	 */

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputMappingContext* IMC;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* Looking;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* PauseAction;


	/*
	 * Waves
	 */
	void StartWave();

	bool WaveEnded = false;

	void EndWave();
	
	// End
	
	
protected:
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
