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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Heat Capsule")
	class UCapsuleComponent* GiveHeatCapsule;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Glue Box")
	class UBoxComponent* BoxAttachment;
	//
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fire")
	//class UNiagaraSystem* StylizedFire

	//UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Mesh")
	//UStaticMeshComponent* Staticmesh0;
	//
	//UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Mesh")
	//UStaticMeshComponent* Staticmesh1;

	//UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Mesh")
	//UStaticMeshComponent* Staticmesh2;

	//UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Mesh")
	//UStaticMeshComponent* Staticmesh3;

	//UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Mesh")
	//UStaticMeshComponent* Staticmesh4;

	//UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category= "Mesh")
	//UStaticMeshComponent* Staticmesh5;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	//virtual void NotifyActorBeginOverlap(AActor* APoels);
	//virtual void NotifyActorEndOverlap(AActor* APoels);

	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
