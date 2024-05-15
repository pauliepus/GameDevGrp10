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
	// /* Childs from Box 2 - Grill mesh */
	//GrillStaticmesh0 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT(" - Grill Mesh Component"));
	//GrillStaticmesh0->SetupAttachment(BoxAttachment2);	
	//GrillStaticmesh1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT(" - Grill Mesh Component"));
	//GrillStaticmesh1->AttachToComponent(GrillStaticmesh, FAttachmentTransformRules::KeepRelativeTransform);
	//GrillStaticmesh2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT(" - Grill Mesh Component"));
	//GrillStaticmesh2->AttachToComponent(GrillStaticmesh1, FAttachmentTransformRules::KeepRelativeTransform);
	//GrillStaticmesh3 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT(" - Grill Mesh Component"));
	//GrillStaticmesh3->AttachToComponent(GrillStaticmesh2, FAttachmentTransformRules::KeepRelativeTransform);
	//GrillStaticmesh4 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT(" - Grill Mesh Component"));
	//GrillStaticmesh4->AttachToComponent(GrillStaticmesh3, FAttachmentTransformRules::KeepRelativeTransform);

	// overlap event trigger/end
	//GiveHeatCapsule->OnComponentBeginOverlap.AddDynamic(this, &AOverlap::OnOverlapBegin);
	//GiveHeatCapsule->OnComponentEndOverlap.AddDynamic(this, &AOverlap::OnOverlapEnd);
	
}

/*AGrillActor::OnActorBeginOverlap
{

};
*/


//void AGrillActor::TransferHeat()
//{
//}


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

