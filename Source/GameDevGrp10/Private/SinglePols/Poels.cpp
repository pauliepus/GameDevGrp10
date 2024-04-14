// Fill out your copyright notice in the Description page of Project Settings.

#include "SinglePols/Poels.h"
#include "Components/SkeletalMeshComponent.h"



// Sets default values
APoels::APoels()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Creating Static Mesh object and attaching to root component (no real reason to have it tbh)
	SMDefault = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh Default"));
	SMDefault->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);
	
	// Creating Skeletal Mesh objects and attaching to root component
	SKDefault = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Skeletal Mesh"));
	SKDefault->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);

	// (14.4) After /finally/ making these, I realize there was a function to simply Change materials, but I've chosen to just keep it this way.
	SKAlternate = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Skeletal Mesh Alt."));
	SKAlternate->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);

	// (14.4) This is very sub-optimal, because I feel like it adds too much data, but I believe I got carried by the UAssets, ngl.
	SKBurnt= CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Skeletal Mesh Burnt"));
	SKBurnt->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);

}
	
//This is to make the SkelMeshes change
//
//void APoels::SKChanger()
//{ 
//	if (bIsCooked == false)
//	{
//		SKDefault;
//	}
//	else {
//		SKAlternate;
//	};
//}

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
			&APoels::OverCooked,
			BurntTime,
			false
		);
	}
}

void APoels::OverCooked()
{
	bIsOvercooked = true;
	bIsCooked = false;
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

