// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter2.h"

// Sets default values
APlayerCharacter2::APlayerCharacter2()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	///*Camera Component*/
	//FPVCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	//FPVCameraComponent->SetupAttachment(GetCapsuleComponent());
	//FPVCameraComponent->bUsePawnControlRotation = true;

	/*Skeletal Mesh Component*/
	//FPVMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharMesh"));
	//FPVMesh->SetupAttachment(FPVCameraComponent);
}


//// Called to bind functionality to input
//void APlayerCharacter2::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
//{
//	Super::SetupPlayerInputComponent(PlayerInputComponent);
//
//}

void APlayerCharacter2::SetHasWeapon(bool bHasNewWeapon)
{
	bHasWeapon = bHasNewWeapon;
}

bool APlayerCharacter2::GetHasWeapon()
{
	return bHasWeapon;
}


void APlayerCharacter2::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	if (EnhancedInputComponent)
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &APlayerCharacter2::Move);
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &APlayerCharacter2::LookAround);

		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);


	}

}

// Called when the game starts or when spawned
void APlayerCharacter2::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void APlayerCharacter2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}