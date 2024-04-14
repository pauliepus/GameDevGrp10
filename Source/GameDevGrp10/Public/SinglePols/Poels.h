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
		
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "Cooking Timer")
	float CookingTime= 15.0f;

	FTimerHandle TakeStartCookingHandle;
	
	//Cooking thing that makes pøls bool true, meaning it now COUNTS towards pts.

	bool bIsCooked = false;
	void SetIsCookedTrue();
	void CookingComplete();

	//took from here https://forums.unrealengine.com/t/how-to-add-static-mesh-component-in-c/453395

	//UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Custom Textures / Meshes")
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	USkeletalMeshComponent* PolseSMComponent;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
	USkeletalMeshComponent* PolseSMComponentSecond;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	


	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
