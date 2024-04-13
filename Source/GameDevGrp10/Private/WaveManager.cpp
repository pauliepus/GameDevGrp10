// Fill out your copyright notice in the Description page of Project Settings.


#include "WaveManager.h"
#include "EnemySpawner.h"
#include "EngineUtils.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AWaveManager::AWaveManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AWaveManager::BeginPlay()
{
	Super::BeginPlay();

	
	//ActorItr-function was based off code from Bing Copilot
	//Finding the EnemySpawner, so I can start and stop it
	for (TActorIterator<AActor> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		if (ActorItr->GetName().Contains("EnemySpawner"))
		{
			TargetSpawner = static_cast<AEnemySpawner*>(*ActorItr);
		}
	}
	WaveStart();
}

// Called every frame
void AWaveManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWaveManager::WaveStart()
{
	WaveNumber++;
	TargetSpawner->StartSpawning();

	GetWorldTimerManager().SetTimer(
		PauseWave,
		this,
		&AWaveManager::WaveEnd,
		WaveTimer,
		false
	);
}

void AWaveManager::WaveEnd()
{
	TargetSpawner->StopSpawning();

	//Destroying all enemies
	for (TActorIterator<AActor> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		if (ActorItr->GetName().Contains("EnemyBaseCharacter"))
		{
			ActorItr->Destroy();
		}
	}
}
