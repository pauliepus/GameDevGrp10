// Fill out your copyright notice in the Description page of Project Settings.


#include "GrillActor.h"
//#include "Poels.h"
#include "Components/SphereComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/BoxComponent.h"



// Casting learnt from https://docs.unrealengine.com/4.27/en-US/ProgrammingAndScripting/ActorCommunication/CastingQuickStart/ 

// Sets default values
AGrillActor::AGrillActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	

	//APoels* Poels = Cast<APoels>(APoels::SetIsCookedTrue.GetActor());

	
	/* RootComponent in BP */
	BoxAttachment = CreateDefaultSubobject<UBoxComponent>(TEXT("Root - ));
	BoxAttachment->SetupAttachment(GetRootComponent());
	BoxAttachment = RootBoxComponent;

	/* Attaches to RootBoxAttachment */
	GiveHeatCapsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT(" - HeatCapsule - "));
	GiveHeatCapsule->AttachToComponent(RootBoxComponent,FAttachmentTransformRules::KeepRelativeTransform)
	GiveHeatCapsule = HeatComponent;
	HeatComponent->SetCapsuleRadius(50);
	/* Root */
	BoxAttachment2 = CreateDefaultSubobject<UBoxComponent>(TEXT(" - Glue Component - "));
	BoxAttachment2->SetupAttachment(HeatComponent);
	BoxAttachment2 = GlueBoxComponent;
	/* AttachCoComponent KeepsTransforms, physically attaches meshes*/

	
	/* Connects to GlueBoxComponent */
	SMGrillComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT(" - Grill Mesh - "))
	SMGrillComponent = GrillMeshComponent;
	GrillMeshComponent->AttachToComponent(GlueBoxComponent, FAttachmentTransformRules::KeepRelativeTransform);

	/* Transforms to Grill - StaticMeshComponents Attaching to Grill Mesh Component */
	GrillStaticmesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT(" - Grill Mesh Component"));
	GrillStaticmesh->AttachToComponent(GrillMeshComponent, FAttachmentTransformRules::KeepWorldTransform);

	GrillStaticmesh1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT(" - Grill Mesh Component"));
	GrillStaticmesh1->AttachToComponent(GrillMeshComponent, FAttachmentTransformRules::KeepWorldTransform);
	
	GrillStaticmesh2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT(" - Grill Mesh Component"));
	GrillStaticmesh2->AttachToComponent(GrillMeshComponent, FAttachmentTransformRules::KeepRelativeTransform);
	
	GrillStaticmesh3 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT(" - Grill Mesh Component"));
	GrillStaticmesh3->SetupAttachment(GrillMeshComponent);

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

