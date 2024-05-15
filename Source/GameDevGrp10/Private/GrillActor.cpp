// Fill out your copyright notice in the Description page of Project Settings.


#include "GrillActor.h"
#include <Components/BoxComponent.h>
#include <Components/SphereComponent.h>
#include <Components/CapsuleComponent.h>
#include <Poels.h>



// Casting learnt from https://docs.unrealengine.com/4.27/en-US/ProgrammingAndScripting/ActorCommunication/CastingQuickStart/ 

// Sets default values
AGrillActor::AGrillActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	// In your constructor
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Scene Root"));
	RootComponent = SceneRoot;
	// Then to attach your box
	// Now add your offset.
	
	 /* Childs from Root */
	BoxAttachment = CreateDefaultSubobject<UBoxComponent>(TEXT(" - Mesh Root - "));
	BoxAttachment->SetupAttachment(SceneRoot);
	
	// /*  - Gives Heat */
	GiveHeatCapsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT(" - HeatCapsule - "));
	GiveHeatCapsule->AttachToComponent(SceneRoot, FAttachmentTransformRules::KeepRelativeTransform);
	GiveHeatCapsule->SetGenerateOverlapEvents(true);

	/* Childs from Heat - Box */
	BoxAttachment2 = CreateDefaultSubobject<UBoxComponent>(TEXT(" - Glue Box Component - "));
	BoxAttachment2->SetupAttachment(SceneRoot);
			
}

void AGrillActor::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	APoels* PoelsActor = Cast<APoels>(OtherActor);
	if (PoelsActor)
	{
		PoelsActor->SetIsCookedTrue();
	}
}

 /* BEGIN PLAY */ 
void AGrillActor::BeginPlay()
{
	Super::BeginPlay();
	
	GiveHeatCapsule->OnComponentBeginOverlap.AddDynamic(this, &AGrillActor::OnOverlapBegin);

}

// Called every frame
void AGrillActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

