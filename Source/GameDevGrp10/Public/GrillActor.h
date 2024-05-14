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

	//TransferHeat();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	class UCapsuleComponent* GiveHeatCapsule;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	class UBoxComponent* BoxAttachment;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UStaticMeshComponent* Staticmesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UStaticMeshComponent* Staticmesh1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UStaticMeshComponent* Staticmesh2;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UStaticMeshComponent* Staticmesh3;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UStaticMeshComponent* Staticmesh4;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UStaticMeshComponent* Staticmesh5;
	
	virtual void NotifyActorBeginOverlap(AActor* APoels);
	virtual void NotifyActorEndOverlap(AActor* APoels);

	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
