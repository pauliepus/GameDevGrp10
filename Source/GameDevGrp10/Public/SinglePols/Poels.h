// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SkeletalMeshComponent.h"
#include "Runtime/Engine/Public/TimerManager.h"
#include "Poels.generated.h"

UCLASS()
class GAMEDEVGRP10_API APoels : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APoels();
	
	/* Cooking Pølse Timer */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cooking Timer")
	float CookingTime = 15.0f;
	
	/* Overcooking Pølse Timer */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Burnt Timer")
	float BurntTime = 10.0f;


	FTimerHandle TakeStartCookingHandle;
	
	/**/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsCooked = false;
	UFUNCTION(BlueprintCallable)
	void SetIsCookedTrue();
	
	/*
	the boolean funct for timer and mesh change(which should've been M_), needs to be called in BP.
	*/
	UFUNCTION(BlueprintCallable)
	void CookingComplete();
	
	/*
	* Overcook FTimerHandle connected to the Overcook function
	*/
	FTimerHandle TakeStartOvercookHandle;
	
	/*
	*Burnt checker
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsOvercooked = false;
	UFUNCTION(BlueprintCallable)
	void SetIsOvercookedTrue();
	
	UFUNCTION(BlueprintCallable)
	void OverCookingComplete();

	UFUNCTION(BlueprintCallable)
	void StopTimers();
		
	//took from here https://forums.unrealengine.com/t/how-to-add-static-mesh-component-in-c/453395
	//not sure if it actually helped me tbh.
	
	/*
	* MESHES
	*/

	/* CapsuleComponent Class + Pointer */
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
	class UBoxComponent* BoxAttachment;

	/* SkeletalMesh Pointer */
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
	USkeletalMeshComponent* SKDefault;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn")
	TSubclassOf<APoels> SpawnPoels;
	
	


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	


	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
