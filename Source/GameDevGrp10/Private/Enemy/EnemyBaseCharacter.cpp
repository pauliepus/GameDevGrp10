// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/EnemyBaseCharacter.h"

#include "Kismet/GameplayStatics.h"

// Sets default values
AEnemyBaseCharacter::AEnemyBaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemyBaseCharacter::BeginPlay()
{
	Super::BeginPlay();

	//Remembers player
	Player = UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetPawn();
	GetMesh()->SetGenerateOverlapEvents(true);
}

// Called every frame
void AEnemyBaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bEnemyDead == false)
	{

		if (IsOverlappingActor(Player))
		{
			bEnemyDead = true;
			GetMesh()->SetEnableGravity(true);
			GetMesh()->SetSimulatePhysics(true);
			GetMesh()->bPauseAnims = true;

			GetWorldTimerManager().SetTimer(
				StopDie,
				this,
				&AEnemyBaseCharacter::EnemyDie,
				DeathTimer,
				true);

		}
	}

}

// Called to bind functionality to input
void AEnemyBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


void AEnemyBaseCharacter::EnemyDie()
{
	Destroy();
}

