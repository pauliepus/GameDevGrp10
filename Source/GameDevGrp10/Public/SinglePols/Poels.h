// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SkeletalMeshComponent.h"
#include "Poels.generated.h"

UCLASS()
class GAMEDEVGRP10_API APoels : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APoels();
	
	//void SKChanger();

	//Cooking
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "Cooking Timer")
	float CookingTime= 15.0f;
	
	//Burning
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Burnt Timer")
	float BurntTime = 10.0f;


	FTimerHandle TakeStartCookingHandle;
	
	/*
	* (20.3)Cooking thing that makes pøls bool true, meaning it now COUNTS towards pts. 
	* (14.4) aw shucks, I just realized this is kinda dumb, cause, if it's burnt, it's now not cooked, therefore it can cook again. Shucks
	*/

	bool bIsCooked = false;
	void SetIsCookedTrue();
	
	//the boolean funct for timer and mesh change (which should've been M_), needs to be called in BP.
	UFUNCTION(BlueprintCallable)
	void CookingComplete();
	
	/*
	* (14.4) Overcooking / Burning the pøls function
	*/

	FTimerHandle TakeStartOvercookHandle;
	
	/*
	*Burnt checker
	*/
	
	bool bIsOvercooked = false;
	void SetIsOvercookedTrue();
	
	UFUNCTION(BlueprintCallable)
	void OverCooked();

	//took from here https://forums.unrealengine.com/t/how-to-add-static-mesh-component-in-c/453395
	//not sure if it actually helped me tbh.
	
	/*
	MESHES
	*/
	//Skeletons
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
	USkeletalMeshComponent* SKDefault;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
	USkeletalMeshComponent* SKAlternate;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	USkeletalMeshComponent* SKBurnt;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	


	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
