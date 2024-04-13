// Fill out your copyright notice in the Description page of Project Settings.


#include "SinglePols/Poels.h"
#include "Components/StaticMeshComponent.h"


// Sets default values
APoels::APoels()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Creating Static Mesh object and attaching to root component
	PolseMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static mesh"));
	PolseMeshComponent->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);

	// Creating Static Mesh object and attaching to root component
	PolseMeshComponentSecond = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static mesh 2"));
	PolseMeshComponentSecond->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);

}

void APoels::SetIsCookedTrue()
{
	bIsCooked = false;

	GetWorld()->GetTimerManager().SetTimer(
		TakeStartCookingHandle,
		this,
		&APoels::CookingComplete,
		CookingTime,
		false
	);
}

void APoels::CookingComplete()
{
	bIsCooked = true;
}

// Called when the game starts or when spawned
void APoels::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APoels::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

