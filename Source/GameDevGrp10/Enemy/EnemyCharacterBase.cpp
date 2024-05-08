// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyCharacterBase.h"

// Sets default values
AEnemyCharacterBase::AEnemyCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemyCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemyCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemyCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
//Sets a timer until the enemy is de-spawned
void AEnemyCharacterBase::EnemyDie()
{
	GetMesh()->SetSimulatePhysics(true);

	GetWorldTimerManager().SetTimer(
		StopDie,
		this,
		&AEnemyCharacterBase::EnemyRemove,
		DeathTimer,
		true
	);
}
//De-spawns enemy
void AEnemyCharacterBase::EnemyRemove()
{
	Destroy();
}
//Happens upon reaching a p�lse
void AEnemyCharacterBase::EnemySteal()
{
	Destroy();
}


