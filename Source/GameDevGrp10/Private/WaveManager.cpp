// Fill out your copyright notice in the Description page of Project Settings.


#include "WaveManager.h"
#include "EngineUtils.h"
#include "AssetTypeActions/AssetDefinition_SoundBase.h"

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
	for (TActorIterator<AActor> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		if (ActorItr->GetName().Contains("PlayerCharacter"))
		{
			Player = static_cast<APlayerCharacter*>(*ActorItr);
		}
	}
	WaveStart();
}

// Called every frame
void AWaveManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (ManagerWaveEnded) {
		if (!Player->WaveEnded)
		{
			ManagerWaveEnded = false;
			WaveStart();
		}
	}

}

void AWaveManager::WaveStart()
{
	WaveNumber++;
	TargetSpawner->StartSpawning();
	//This is for the UI at the top of the screen
	Seconds = (WaveTimer-1) % 60;
	Minutes = (WaveTimer-1) / 60;

	GetWorldTimerManager().SetTimer(T_CountDown, this, &AWaveManager::CountDown, 1.0f, true, 1.0f);
	//This handles spawning and is the one that actually ends things
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
		if (ActorItr->GetName().Contains("EnemyCharacter"))
		{
			ActorItr->Destroy();
		}
	}
	GetWorldTimerManager().ClearTimer(T_CountDown);

	if (TrollSequence && TrollSequencePlayer == nullptr)
		TrollSequencePlayer = ULevelSequencePlayer::CreateLevelSequencePlayer(GetWorld(), TrollSequence, FMovieSceneSequencePlaybackSettings(), TrollSequenceActor);

	//Sequence Play
	if (TrollSequencePlayer != nullptr)
	{
		TrollSequencePlayer->Play();
	}


	GetWorldTimerManager().SetTimer(
		StopTroll,
		this,
		&AWaveManager::TrollAnimDone,
		EndWaveDelay,
		false
	);
}

void AWaveManager::TrollAnimDone()
{
	ManagerWaveEnded = true;
	Player->EndWave();
}

void AWaveManager::CountDown()
{
	if (Seconds > 0)
	{
		--Seconds;
		UE_LOG(LogTemp, Warning, TEXT("Seconds %f"), Seconds);
	}
	else
	{
		--Minutes;
		Seconds = 59.0f;
		UE_LOG(LogTemp, Warning, TEXT("Minutes %d"), Minutes);
	}
}



