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
	//Calculate a random spawn position. using pi/2 as max values both positive and negative in order to spawn in a semicircle when using cos and sin
	float SpawnArea = FMath::RandRange(-1.6f, 1.6f);

	//Expanding the semicircle
	float SpawnX = cos(SpawnArea) * 1900.0f;
	float SpawnY = sin(SpawnArea) * 1900.0f;

	//Finding surface by using raytracing
	FVector StartTrace = { SpawnX, SpawnY, 400.0f };
	FVector EndTrace = { SpawnX, SpawnY, -200.0f };

	FHitResult Hit;
	FCollisionQueryParams CollisionParams;

	if (GetWorld()->LineTraceSingleByChannel(Hit, StartTrace, EndTrace, ECC_Visibility, CollisionParams))
	{
		if (Hit.IsValidBlockingHit())
		{
			if (SpawnArea < -1.3f || SpawnArea > 1.3f)
				GetWorld()->SpawnActor<AEnemyCharacterBase>(EnemyRoller, Hit.ImpactPoint, FRotator::ZeroRotator);
			else
				GetWorld()->SpawnActor<AEnemyCharacterBase>(EnemyBase, Hit.ImpactPoint, FRotator::ZeroRotator);
		}
		//If nothing was hit, the Spawn-point was invalid, so a new position to spawn is calculated
		else
		{
			SpawnEnemy();
		}
	}
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
//Makes enemies spawn more often for each wave that ends
void AEnemySpawner::StopSpawning()
{
	GetWorldTimerManager().ClearTimer(WavePause);
	SpawnTimer -= SpawnTimer / 30;
}