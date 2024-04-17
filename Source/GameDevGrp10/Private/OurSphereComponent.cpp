// Fill out your copyright notice in the Description page of Project Settings.


#include "OurSphereComponent.h"

// Sets default values
UOurSphereComponent::UOurSphereComponent()
{
	SphereRadius = 30.0f;
}

// Called when the game starts or when spawned
void UOurSphereComponent::BeginPlay()
{
	Super::BeginPlay();
	
	OnComponentBeginOverlap.AddDynamic(this, &UOurSphereComponent::OnSphereBeginOverlap);

}

void UOurSphereComponent::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	APlayerCharacter* Character = Cast<APlayerCharacter>(OtherActor);
	if (Character != nullptr)
	{
		//OnPickUp.Broadcast(Character);
		OnComponentBeginOverlap.RemoveAll(this);
	}
}
