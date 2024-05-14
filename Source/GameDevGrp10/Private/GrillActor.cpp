// Fill out your copyright notice in the Description page of Project Settings.


#include "GrillActor.h"
#include "Components/CapsuleComponent.h"
#include "Components/BoxComponent.h"


// Sets default values
AGrillActor::AGrillActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	APoels* Polse;

	////RootComponent in BP,
//
	//GiveHeatCapsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Root - HeatCapsule"));
	//RootComponent = GiveHeatCapsule;
	
	//()()Attachtocomponent physically attaches
	//This component connects to the RootComponent and grants mesh connect, :
	BoxAttachment = CreateDefaultSubobject<UBoxComponent>(TEXT("Sub-root - Glue Box"));
	BoxAttachment->SetupAttachment(RootComponent);
	//Meshes connecting to BoxComponent below


}

void AGrillActor::TransferHeat() 
{
	Polse = Cast<APoels>(this, );
	if(bUncooked)

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

