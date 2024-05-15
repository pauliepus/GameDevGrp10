// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <Components/SkeletalMeshComponent.h>
#include <Components/BoxComponent.h>
#include <Components/SphereComponent.h>
#include "Runtime/Engine/Public/TimerManager.h"
#include "Poels.generated.h"

UCLASS()
class GAMEDEVGRP10_API APoels : public AActor
{
	GENERATED_BODY()
public:
	// Sets default values for this actor's properties
	APoels();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Bools")
	bool bIsCooked = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Bools")
	bool bIsOvercooked = false;

	// Called every frame
	virtual void Tick(float DeltaTime) override;
		
	/* Cooking Pølse Timer */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cooking Timer")
	float CookingTime = 15.0f;

	/* Overcooking Pølse Timer */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Burnt Timer")
	float BurntTime = 10.0f;

	//UFUNCTION()
	//void OnOverlapActivateCook(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);


private:

	FTimerHandle TakeStartCookingHandle;

	FTimerHandle TakeStartOvercookHandle;

public:

	UFUNCTION(BlueprintCallable)
	void SetIsCookedTrue();
	
	 /* the boolean funct for timer and mesh change(which should've been M_), needs to be called in BP. */
	
	UFUNCTION(BlueprintCallable)
	void CookingComplete();
	
	 /*
	 *Burnt checker
	 */

	UFUNCTION(BlueprintCallable, Category="CookingComponent")
	void SetIsOvercookedTrue();
	
	UFUNCTION(BlueprintCallable)
	void OverCookingComplete();
		
	//took from here https://forums.unrealengine.com/t/how-to-add-static-mesh-component-in-c/453395
	//not sure if it actually helped me tbh.
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class USceneComponent* SceneComponentPoelse;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UBoxComponent* BoxPoelse;

	 /* SkeletalMesh Pointer */
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
	USkeletalMeshComponent* SKDefault;
		
	 /* Sphere Taking heat for overlap of Capsule in Grill */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	class USphereComponent* TakeHeatSphere;
		
};
