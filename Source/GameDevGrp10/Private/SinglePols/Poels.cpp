// Fill out your copyright notice in the Description page of Project Settings.

#include "SinglePols/Poels.h"
#include <GameFramework/Character.h>
#include <Components/BoxComponent.h>


// Sets default values
APoels::APoels()
{
		
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
		
	// Creating Skeletal Mesh objects and attaching to capsule component

	// Box Make and attach to root
	BoxAttachment = CreateDefaultSubobject<UBoxComponent>(TEXT("Collider Box"));
	BoxAttachment->SetupAttachment(GetRootComponent());
	// SKeleton make, and make attach to Box
	SKDefault= CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Skeletal Mesh"));
	SKDefault->SetupAttachment(BoxAttachment);
	// Safety bools for when making children
	bIsCooked = false;
	bIsOvercooked = false;
	// Sphere make, and attach to... not root? uhh, box. Okay..
	TakeCookingPower = CreateDefaultSubobject<USphereComponent>(TEXT("Heat Taker Sphere"));
	TakeCookingPower->SetupAttachment(BoxAttachment);

}

/*
* COOKED, they do be gettin' 'lit
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
				
}

// Called every frame
void APoels::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

