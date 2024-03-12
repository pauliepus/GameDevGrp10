// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyBase.h"

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

}

// Called when the game starts or when spawned
void AEnemyBase::BeginPlay()
{
	Super::BeginPlay();


	
}

// Called every frame
void AEnemyBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//Movement
	FVector Location = GetActorLocation();

	Location += GetActorForwardVector() * Speed * DeltaTime;

	SetActorLocation(Location);

}

void AEnemyBase::EnemyMove()
{
}

