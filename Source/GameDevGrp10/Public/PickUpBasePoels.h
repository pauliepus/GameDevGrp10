// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractInterface.h"
#include "GameFramework/Actor.h"
#include "PickUpBasePoels.generated.h"


/*
 * Pickup based on https://youtu.be/cBnYYois1vM
 * PickupBool from https://youtu.be/iUq3rDvbUhM
 */

UCLASS()
class GAMEDEVGRP10_API APickUpBasePoels : public AActor, public IInteractInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickUpBasePoels();

	//PickupBool part

	UFUNCTION(BlueprintPure,Category="Pickup")
	bool bIsPickupActive() const;

	UFUNCTION(BlueprintCallable,Category="Pickup")
	void SetPickupIsActive(bool NewActiveState);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//PickupBool part
	bool bIsActive;


#pragma region COMPONENTS

	UPROPERTY(VisibleAnywhere, Category="Components")
	UStaticMeshComponent* PickupMesh;

#pragma endregion

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void Interact_Implementation() override;
	
	UFUNCTION()
	void pickup();

};
