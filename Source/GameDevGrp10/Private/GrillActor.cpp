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
	GiveHeatCapsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Root - HeatCapsule"));
	GiveHeatCapsule->SetCapsuleRadius(200);
	RootComponent = GiveHeatCapsule;

	
	//()()Attachtocomponent physically attaches
	
	//This component connects to the RootComponent and grants mesh connect, :
	BoxAttachment = CreateDefaultSubobject<UBoxComponent>(TEXT("Sub-root - Glue Box"));
	BoxAttachment->SetupAttachment(RootComponent);

	//Meshes connecting to BoxComponent
	Staticmesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	
	Staticmesh1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh1"));
	
	Staticmesh2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh2"));
	
	Staticmesh3 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh3"));
	
	Staticmesh4 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh4"));
	
	Staticmesh5 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh5"));

}

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

