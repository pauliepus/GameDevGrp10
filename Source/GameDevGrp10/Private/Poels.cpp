// Fill out your copyright notice in the Description page of Project Settings.

#include "Poels.h"
#include "GrillActor.h"
#include "Engine/Engine.h"
#include <GameFramework/Character.h>
#include <Components/SkeletalMeshComponent.h>
#include <Components/BoxComponent.h>
#include <Components/SphereComponent.h>
#include "TimerManager.h"


// Sets default values
APoels::APoels()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Bools")
	bIsCooked = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Bools")
	bIsOvercooked = false;

	// Creating Skeletal Mesh objects and attaching to capsule component
	// Because Poels is an Actor and not Character, it cannot move yet. This will be fixed later

	RootComponent = BoxPoelse;
	 /* Creating Components */
	BoxPoelse = CreateDefaultSubobject<UBoxComponent>(TEXT("Asset Box"));
	TakeHeatSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Take Heat Sphere"));
	SKDefault = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Skeletal Mesh"));
	//SKCooked = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Skeletal Mesh"));
	//SKOvercooked = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Skeletal Mesh"));
	
	/* Attaching components */
	BoxPoelse->SetupAttachment(RootComponent);
	TakeHeatSphere->SetupAttachment(BoxPoels);
	SKDefault->SetupAttachment(TakeHeatSphere);

	//SKCooked->bSetVisibility(false);

	 /* Component Attributes */
	TakeHeatSphere->InitSphereRadius(25);
	TakeHeatSphere->SetGenerateOverlapEvents(true);
	TakeHeatSphere->SetCollisionProfileName(TEXT("OverlapPoelse"));

	//TakeHeatSphere->OnComponentBeginOverlap.AddDynamic(this, &APoels::OnOverlapActivateCook);
	

	

}

void APoels::SetIsCookedTrue()
{
	bIsCooked = false;
	if (!bIsOvercooked) {
		GetWorld()->GetTimerManager().SetTimer(
			TakeStartCookingHandle,
			this,
			&APoels::CookingComplete,
			CookingTime,
			false
		);
		bIsCooked = true;
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

void APoels::OnOverlapActivateCook(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("It takes heat"));
		
		//SetIsCookedTrue();
	}

}

// Called every frame
void APoels::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

