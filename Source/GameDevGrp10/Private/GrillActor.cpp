// Fill out your copyright notice in the Description page of Project Settings.


#include "GrillActor.h"
#include "Poels.h"
#include <Components/BoxComponent.h>
#include <Components/SphereComponent.h>
#include <Components/CapsuleComponent.h>



// Casting learnt from https://docs.unrealengine.com/4.27/en-US/ProgrammingAndScripting/ActorCommunication/CastingQuickStart/ 

// Sets default values
AGrillActor::AGrillActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Scene Root"));
	RootComponent = SceneRoot;
	
	 /* Childs from Root */
	
	// /*  - Gives Heat */
	GiveHeatCapsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT(" - HeatCapsule - "));
	GiveHeatCapsule->AttachToComponent(SceneRoot, FAttachmentTransformRules::KeepRelativeTransform);
	GiveHeatCapsule->SetGenerateOverlapEvents(true);

	/* Childs from Heat - Box */
	BoxAttachment = CreateDefaultSubobject<UBoxComponent>(TEXT(" - Glue Box Component - "));
	BoxAttachment->SetupAttachment(GiveHeatCapsule);
	BoxAttachment->SetCollisionProfileName(TEXT("OverlapPoelse"));


}

void AGrillActor::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActorParam,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Display, TEXT(" cooking "));
	APoels* PoelsActor = Cast<APoels>(OtherActorParam);
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

