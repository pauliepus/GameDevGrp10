// Fill out your copyright notice in the Description page of Project Settings.


#include "GrillActor.h"
//#include "Poels.h"
#include "Components/BoxComponent.h"
#include "Components/SphereComponent.h"
#include "Components/CapsuleComponent.h"



// Casting learnt from https://docs.unrealengine.com/4.27/en-US/ProgrammingAndScripting/ActorCommunication/CastingQuickStart/ 

// Sets default values
AGrillActor::AGrillActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	bool GetGenerateOverlapEvents(true) const;
	//APoels* Poels = Cast<APoels>(APoels::SetIsCookedTrue.GetActor());

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
	
	// GiveHeatCapsule->SetRelativeTransform(FAttachmentTransformRules::KeepRelativeTransform);
	GiveHeatCapsule->AttachToComponent(SceneRoot, FAttachmentTransformRules::KeepRelativeTransform);
	GiveHeatCapsule->SetCapsuleRadius(50);
	
	/* Childs from Heat - Box */
	BoxAttachment2 = CreateDefaultSubobject<UBoxComponent>(TEXT(" - Glue Box Component - "));
	BoxAttachment2->SetupAttachment(SceneRoot);
	
		
}



// Called when the game starts or when spawned
void AGrillActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGrillActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

