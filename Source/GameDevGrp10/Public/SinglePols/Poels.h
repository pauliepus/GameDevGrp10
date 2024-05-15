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
	bool bIsCooked = false;
	
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
	bool bIsOvercooked = false;
	UFUNCTION(BlueprintCallable, Category="CookingComponent")
	void SetIsOvercookedTrue();
	
	UFUNCTION(BlueprintCallable)
	void OverCookingComplete();
		
	//took from here https://forums.unrealengine.com/t/how-to-add-static-mesh-component-in-c/453395
	//not sure if it actually helped me tbh.
	
	/*
	* MESHES
	*/

	/* BoxComponent Class + Pointer */
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
	class UBoxComponent* BoxAttachment;

	/* SkeletalMesh Pointer */
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
	USkeletalMeshComponent* SKDefault;

	/* Sphere Taking heat for overlap of Capsule in Grill */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	class USphereComponent* TakeHeatSphere;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UFUNCTION()
	void OnOverlapActivateCook(UPrimitiveComponent* TakeHeatSphere,
		AActor* AGrillActor,
		UPrimitiveComponent* GiveHeatCapsule, int32 OtherBodyIndex);
	

public:	


	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
