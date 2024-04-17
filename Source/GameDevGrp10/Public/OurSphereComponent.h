// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerCharacter.h"
#include "Components/SphereComponent.h"
#include "OurSphereComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPickUp, APlayerCharacter*, PickUpCharacter);


UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class GAMEDEVGRP10_API UOurSphereComponent : public USphereComponent
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties

	virtual void BeginPlay() override;
	//UPROPERTY(BlueprintAssignable, Category = "Interaction")
	//FOnPickup OnPickup;
	
	void AOurSphereComponent();

	UOurSphereComponent();

	UFUNCTION()
	void OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
		bool bFromSweep, const FHitResult& SweepResult);


};
