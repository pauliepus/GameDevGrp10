// Fill out your copyright notice in the Description page of Project Settings.

#include "SinglePols/Poels.h"
#include "Components/SkeletalMeshComponent.h"
#include <GameFramework/Character.h>
#include <Components/BoxComponent.h>
//#include <PolseEnum.h>


// Sets default values
APoels::APoels()
{
		
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
		
	// Creating Skeletal Mesh objects and attaching to capsule component

	BoxAttachment = CreateDefaultSubobject<UBoxComponent>(TEXT("Asset Box"));
	BoxAttachment->SetupAttachment(GetRootComponent());

	SKDefault= CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Skeletal Mesh"));
	SKDefault->SetupAttachment(BoxAttachment);
	
	bIsCooked = false;
	bIsOvercooked = false;
	
}

/*
* COOKED
*/

void APoels::IsCookedTrue()
{
	bIsCooked = false;
	
	if (bIsOvercooked == false) {
		GetWorld()->GetTimerManager().SetTimer(
			TakeStartCookingHandle,
			this,
			&APoels::SetIsCookedTrue,
			CookingTime,
			false
		);
	}
}

void APoels::SetIsCookedTrue()
{
	bIsCooked = true;
}

/*
* OVERCOOKS
*/
void APoels::StartOverCook()
{
	bIsOvercooked = false;

	if (bIsCooked == true)
	{
		GetWorld()->GetTimerManager().SetTimer(
			TakeStartOvercookHandle,
			this,
			&APoels::SetIsOverCookedTrue,
			OverCookingTime,
			false
		);
	}
}


void APoels::SetIsOverCookedTrue()
{
	bIsCooked = false;
	bIsOvercooked = true;
}


// Called when the game starts or when spawned
void APoels::BeginPlay()
{
	Super::BeginPlay();
	
	BoxAttachment->OnComponentBeginOverlap.__Internal_AddDynamic(this, get(IsCookedTrue))
		
}

// Called every frame
void APoels::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

