// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemySpawner.h"

// Sets default values
AEnemySpawner::AEnemySpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	

}

// Called when the game starts or when spawned
void AEnemySpawner::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(
		WavePause,
		this,
		&AEnemySpawner::SpawnEnemy,
		SpawnTimer,
		true
	);
	
}

// Called every frame
void AEnemySpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

void AEnemySpawner::SpawnEnemy()
{
	//Calculate a random spawn position
	float SpawnX = FMath::RandRange(1.0f, 1000.0f);
	float SpawnY = FMath::RandRange(1.0f, 1000.0f);
	float SpawnZ = 100.0f;
	FVector SpawnPosition = FVector(SpawnX, SpawnY, SpawnZ);

	GetWorld()->SpawnActor<AEnemyBase>(EnemyClass, SpawnPosition, FRotator::ZeroRotator);

	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Some debug message!"));
}

