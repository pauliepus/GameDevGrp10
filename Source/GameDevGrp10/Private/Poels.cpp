// Fill out your copyright notice in the Description page of Project Settings.

#include "Poels.h"
#include <GameFramework/Character.h>
#include <Components/SkeletalMeshComponent.h>
#include <Components/BoxComponent.h>
#include <Components/SphereComponent.h>


// Sets default values
APoels::APoels()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	
	// Creating Skeletal Mesh objects and attaching to capsule component
	// Because Poels is an Actor and not Character, it cannot move yet. This will be fixed later
	BoxAttachment = CreateDefaultSubobject<UBoxComponent>(TEXT("Asset Box"));
	BoxAttachment->SetupAttachment(GetRootComponent());

	SKDefault = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Skeletal Mesh"));
	SKDefault->SetupAttachment(BoxAttachment);

	TakeHeatSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Take Heat Sphere"));
	TakeHeatSphere->AttachToComponent(SKDefault, FAttachmentTransformRules::KeepRelativeTransform);
	TakeHeatSphere->InitSphereRadius(25);
	TakeHeatSphere->SetGenerateOverlapEvents(true);

	TakeHeatSphere->OnComponentBeginOverlap.AddDynamic(this, &APoels::OnOverlapActivateCook);
	
	TakeHeatSphere->SetCollisionProfileName(TEXT("OverlapAllDynamic"));

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
	
	bool UpdateOverlaps
	(
		const TOverlapArrayView * PendingOverlaps,
		bool bDoNotifies,
		const TOverlapArrayView * OverlapsAtEndLocation
	);

	

}

void APoels::OnOverlapActivateCook(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("It takes heat"));
		SetIsCookedTrue();
}

// Called every frame
void APoels::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

