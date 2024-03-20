// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyBase.h"
#include <Kismet/KismetMathLibrary.h>
#include "Kismet/GameplayStatics.h"
#include "Components/SphereComponent.h"

// Sets default values
AEnemyBase::AEnemyBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
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

}

// Called when the game starts or when spawned
void AEnemyBase::BeginPlay()
{
	Super::BeginPlay();
	EnemyMesh->SetEnableGravity(true);

	Player = UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetPawn();
	
}

// Called every frame
void AEnemyBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector Direction = Player->GetActorLocation() - GetActorLocation();
	FRotator DirectionRotator = Direction.Rotation();

	SetActorRotation(DirectionRotator, ETeleportType::TeleportPhysics);
	//SetActorLocation(GetActorLocation() + (Direction * Speed * DeltaTime));

}


void AEnemyBase::EnemyTarget(AActor* Target)
{
	//FVector ToTarget = Target->GetActorLocation() - GetActorLocation();
	//ToTarget.Normalize();
	//FRotator NewRotation = UKismetMathLibrary::FindLookAtRotation(GetActorForwardVector(), ToTarget);
	//SetActorRotation(NewRotation);
}





