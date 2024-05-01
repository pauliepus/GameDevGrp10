// Fill out your copyright notice in the Description page of Project Settings.

#include "SinglePols/Poels.h"
#include "Components/SkeletalMeshComponent.h"
#include <GameFramework/Character.h>
#include <Components/BoxComponent.h>


// Sets default values
APoels::APoels()
{
		
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	// Creating Skeletal Mesh objects and attaching to capsule component

	BoxAttachment = CreateDefaultSubobject<UBoxComponent>(TEXT("Asset Box"));
	BoxAttachment->SetupAttachment(GetRootComponent());

	SKDefault = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Skeletal Mesh"));
	SKDefault->SetupAttachment(BoxAttachment);

}

void APoels::SetIsCookedTrue()
{
	bIsCooked = false;
	if (bIsOvercooked == false) {
		GetWorld()->GetTimerManager().SetTimer(
			TakeStartCookingHandle,
			this,
			&APoels::CookingComplete,
			CookingTime,
			false
		);
	}
}

void APoels::CookingComplete()
{
	bIsCooked = true;
}

void APoels::SetIsOvercookedTrue()
{
	bIsOvercooked = false;

	if (bIsCooked == true) 
	{
		GetWorld()->GetTimerManager().SetTimer(
			TakeStartOvercookHandle,
			this,
			&APoels::OverCookingComplete,
			BurntTime,
			false
		);

	}
}

void APoels::OverCookingComplete()
{
	bIsOvercooked = true;
	bIsCooked = false;
}


// Called when the game starts or when spawned
void APoels::BeginPlay()
{
	Super::BeginPlay();
	SKDefault->SetSimulatePhysics(true);
}

// Called every frame
void APoels::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

