// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <Components/SkeletalMeshComponent.h>
#include <Components/SphereComponent.h>
#include <Components/BoxComponent.h>
#include "Runtime/Engine/Public/TimerManager.h"
#include "Poels.generated.h"

UCLASS()
class GAMEDEVGRP10_API APoels : public AActor
{
	GENERATED_BODY()
	
public:	
	
	// Sets default values for this actor's properties
	APoels();
	

	//Cooking timer
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Timers")
	float CookingTime = 5.0f;
	
	//Overcooking timer
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Timers")
	float OverCookingTime = 10.0f;


	FTimerHandle TakeStartCookingHandle;
	
	/*
	* (20.3)Cooking thing that makes pøls bool true, meaning it now COUNTS towards pts. 
	* (14.4) aw shucks, I just realized this is kinda dumb, cause, if it's burnt, it's now not cooked, therefore it can cook again. Shucks
	*/

	/*
	Cook checker, Polse Defaults with cooked and Overcooked False.
	These are set by 2 functions, one being a timer, the other setting the bool to true.
	*/
	bool bIsCooked = false;
	//the boolean needs to be called in BP.
	
	/*
	* Well, this starts a timer. Based on what
	*/
	void IsCookedTrue();
	
	UFUNCTION(BlueprintCallable, Category="bools")
	void SetIsCookedTrue();
	
	/*
	*  Overcooking / Burning the pøls function
	*/
	
	/*
	* Timerhandle, part of Unrealtimer to set a timer
	*/

	FTimerHandle TakeStartOvercookHandle;
	
	/*
	* Overcooked, checks if Cooked==true, and if colliding with "heatsphere" on grill
	*/
	
	bool bIsOvercooked = false;

	
	void StartOverCook();
	
	UFUNCTION(BlueprintCallable, Category = "bools")
	void SetIsOverCookedTrue();
	

	//took from here https://forums.unrealengine.com/t/how-to-add-static-mesh-component-in-c/453395
	//not sure if it actually helped me tbh.
	
	/*
	* Attributes? components?
	*/

	//Box Component, doesn't need to #include <box> cause of "class" infront of it 
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	class UBoxComponent* BoxAttachment;

	USphereComponent* TakeCookingPower;

	//Skeleton's mesh
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	USkeletalMeshComponent* SKDefault;

	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	


	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
