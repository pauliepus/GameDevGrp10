// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <Components/BoxComponent.h>
#include <Components/CapsuleComponent.h>
#include <Components/StaticMeshComponent.h>
#include "GrillActor.generated.h"

UCLASS()
class GAMEDEVGRP10_API AGrillActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGrillActor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USceneComponent* SceneRoot = nullptr;

	 /* Box Attaches to Root */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UBoxComponent* BoxAttachment;
	
	 /* Capsule Attaches To Box 1*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UCapsuleComponent* GiveHeatCapsule;

	 /* Box2 Attaches to Capsule */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UBoxComponent* BoxAttachment2;

	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	
		
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
