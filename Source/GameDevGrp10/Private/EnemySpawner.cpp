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
	
}

// Called every frame
void AEnemySpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}
//Based on Meisams RainManager
void AEnemySpawner::SpawnEnemy()
{
	//Calculate a random spawn position
	float SpawnArea = FMath::RandRange(-1.6f, 1.6f);

	float SpawnX = cos(SpawnArea) * 1900.0f;
	float SpawnY = sin(SpawnArea) * 1900.0f;

	float SpawnZ = 20.0f;
	FVector SpawnPosition = FVector(SpawnX, SpawnY, SpawnZ);

	GetWorld()->SpawnActor<AEnemyBaseCharacter>(EnemyClass, SpawnPosition, FRotator::ZeroRotator);

	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Some debug message!"));
}

void AEnemySpawner::StartSpawning()
{
	GetWorldTimerManager().SetTimer(
		WavePause,
		this,
		&AEnemySpawner::SpawnEnemy,
		SpawnTimer,
		true
	);
}

void AEnemySpawner::StopSpawning()
{
	GetWorldTimerManager().ClearTimer(WavePause);
	
}

