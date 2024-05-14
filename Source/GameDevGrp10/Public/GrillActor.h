// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <Components/StaticMeshComponent.h>
#include "GrillActor.generated.h"

UCLASS()
class GAMEDEVGRP10_API AGrillActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGrillActor();


	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	class UBoxComponent* BoxAttachment;
	
	/* Attaches to Root */

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	class UCapsuleComponent* GiveHeatCapsule;
	//TransferHeat();
	
	/* Attaches to HeatComponent */

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	class UBoxComponent* BoxAttachment2;
	
	/* Attaches to HeatBoxComponent, is mesh */

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	class UStaticMeshComponent* SMGrillComponent;

	/* Attaches to GrillComponent Meshes */

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UStaticMeshComponent* GrillStaticmesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UStaticMeshComponent* GrillStaticmesh1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UStaticMeshComponent* GrillStaticmesh2;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UStaticMeshComponent* GrillStaticmesh3;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	
	//virtual void NotifyActorBeginOverlap(AActor* APoels);
	//virtual void NotifyActorEndOverlap(AActor* APoels);

	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
