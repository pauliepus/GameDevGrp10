// Fill out your copyright notice in the Description page of Project Settings.


#include "WaveManager.h"
#include "EngineUtils.h"

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

		if (ActorItr->GetName().Contains("PlayerCharacter"))
		{
			Player = static_cast<APlayerCharacter*>(*ActorItr);
		}
	}
	
}

// Called every frame
void AWaveManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Starts wave upon player start wave input.
	//WaveManager has direct access to player, but player does not have as easy of a connection, so start wave is placed in WaveManager
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
	//Higher WaveNumber means enemies spawn faster
	WaveNumber++;
	TargetSpawner->StartSpawning();

	//This is for the UI at the top of the screen
	Seconds = (WaveTimer) % 60;
	Minutes = (WaveTimer) / 60;

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
	//stops timer from counting
	GetWorldTimerManager().ClearTimer(T_CountDown);

	//Only makes the SequencePlayer if it does not already exist
	if (TrollSequence && TrollSequencePlayer == nullptr)
		TrollSequencePlayer = ULevelSequencePlayer::CreateLevelSequencePlayer(GetWorld(), TrollSequence, FMovieSceneSequencePlaybackSettings(), TrollSequenceActor);

	//Sequence Play
	if (TrollSequencePlayer != nullptr)
	{
		TrollSequencePlayer->Play();
	}

	//Sets a timer for the animation, so that the player cannot start a new wave while the end of round animation is playing
	GetWorldTimerManager().SetTimer(
		StopTroll,
		this,
		&AWaveManager::TrollAnimDone,
		fEndWaveDelay,
		false
	);
}
//After this, the player can start a new wave
void AWaveManager::TrollAnimDone()
{
	ManagerWaveEnded = true;
	Player->EndWave();
}
//Used for Timer Widget
void AWaveManager::CountDown()
{
	if (Seconds > 0)
	{
		--Seconds;
	}
	else
	{
		--Minutes;
		Seconds = 59.0f;
	}
}



