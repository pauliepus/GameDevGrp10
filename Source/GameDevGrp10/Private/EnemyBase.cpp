// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyBase.h"
#include <Kismet/KismetMathLibrary.h>
#include "Kismet/GameplayStatics.h"
#include "Components/SphereComponent.h"

// Sets default values
AEnemyBase::AEnemyBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Create root
	EnemyRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = EnemyRoot;

	//Create Mesh
	EnemyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	EnemyMesh->SetupAttachment(RootComponent);

	//Create Collision
	EnemyHitbox = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionSphere"));
	EnemyHitbox->SetupAttachment(EnemyMesh);

	EnemyMesh->SetSimulatePhysics(true);
	EnemyMesh->SetGenerateOverlapEvents(true);

}

// Called when the game starts or when spawned
void AEnemyBase::BeginPlay()
{
	Super::BeginPlay();
	EnemyMesh->SetEnableGravity(true);

	Player = UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetPawn();
	
}

// Called every frame
void AEnemyBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//Movement
	//FVector Location = GetActorLocation();

	//Location += GetActorForwardVector() * Speed * DeltaTime;

	//SetActorLocation(Location);

}


void AEnemyBase::EnemyTarget(AActor* target)
{
	FVector toTarget = target->GetActorLocation() - GetActorLocation();
	toTarget.Normalize();
	FRotator newRotation = UKismetMathLibrary::FindLookAtRotation(GetActorForwardVector(), toTarget);
	SetActorRotation(newRotation);
}





