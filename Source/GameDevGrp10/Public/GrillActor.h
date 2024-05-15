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
	//TransferHeat();

	USceneComponent* SceneComponent;
	/* Box Attaches to Root */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UBoxComponent* BoxAttachment;
	
	/* Capsule Attaches To Box 1*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UCapsuleComponent* GiveHeatCapsule;
	
	/* Box Attaches to HeatCapsule */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UBoxComponent* BoxAttachment2;
	
	/* Mesh Attaches to Box 2 */
	UPROPERTY(EditAnywhere, BlueprintReadwrite)
	UStaticMeshComponent* GrillStaticmesh0;
		
	UPROPERTY(EditAnywhere, BlueprintReadwrite)
	UStaticMeshComponent* GrillStaticmesh1;

	UPROPERTY(EditAnywhere, BlueprintReadwrite)
	UStaticMeshComponent* GrillStaticmesh2;

	UPROPERTY(EditAnywhere, BlueprintReadwrite)
	UStaticMeshComponent* GrillStaticmesh3;

	UPROPERTY(EditAnywhere, BlueprintReadwrite)
	UStaticMeshComponent* GrillStaticmesh4;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	
	//virtual void NotifyActorBeginOverlap(AActor* APoels);
	//virtual void NotifyActorEndOverlap(AActor* APoels);

	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
