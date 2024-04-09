// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyBasePawn.h"

#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AEnemyBasePawn::AEnemyBasePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Create Mesh
	EnemyMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	RootComponent = EnemyMesh;


	//Create Collision
	EnemyHitBox = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionSphere"));
	EnemyHitBox->SetupAttachment(RootComponent);

	//Does not work for skeletal mesh
	//EnemyMesh->SetSimulatePhysics(true);

	EnemyMesh->SetGenerateOverlapEvents(true);
	EnemyMesh->SetEnableGravity(true);
	EnemyMesh->SetSimulatePhysics(true);

}

// Called when the game starts or when spawned
void AEnemyBasePawn::BeginPlay()
{
	Super::BeginPlay();
	Player = UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetPawn();

}

// Called every frame
void AEnemyBasePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bEnemyDead == false)
	{
		//FVector Direction = Player->GetActorLocation() - GetActorLocation();
		//FRotator DirectionRotator = Direction.Rotation();

		//SetActorRotation(DirectionRotator, ETeleportType::TeleportPhysics);
		//SetActorLocation(GetActorLocation() + (Direction * Speed * DeltaTime));


		if (IsOverlappingActor(Player))
		{
			bEnemyDead = true;
			EnemyMesh->SetEnableGravity(true);
			EnemyMesh->SetSimulatePhysics(true);
			EnemyMesh->bPauseAnims = true;

			GetWorldTimerManager().SetTimer(
				StopDie,
				this,
				&AEnemyBasePawn::EnemyDie,
				DeathTimer,
				true);

		}
	}
}

// Called to bind functionality to input
void AEnemyBasePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AEnemyBasePawn::EnemyDie()
{
	Destroy();
}

