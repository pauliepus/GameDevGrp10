// Fill out your copyright notice in the Description page of Project Settings.


#include "BaselinePickup.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Kismet/GameplayStatics.h"


UBaselinePickup::UBaselinePickup()
{
	GuntipOffset = FVector(100.0f, 0.0f, 10.0f);
}

void UBaselinePickup::AttachComponentToPlayer(APlayerCharacter* TargetCharacter)
{
	if(Character == nullptr||Character->GetHasWeapon())
	{
		return;
	}

	FAttachmentTransformRules AttachmentRules(EAttachmentRule::SnapToTarget, true);

	AttachToComponent(Character->GetMesh(), AttachmentRules, FName(TEXT("AttachSocket")));

	Character->SetHasWeapon(true);
	//IMC
	APlayerController* PlayerController = Cast<APlayerController>(Character->GetController());
	if(PlayerController)
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem =
			ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(ItemIMC, 1);
		}

		UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerController->InputComponent);

			if (EnhancedInputComponent)
			{
				EnhancedInputComponent->BindAction(UseAction, ETriggerEvent::Triggered, this, &UBaselinePickup::Use);
			}
	}

}

void UBaselinePickup::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if (Character == nullptr)
	{
		return;
	};
}

void UBaselinePickup::Use()
{
	if (ProjectileToSpawn != nullptr)
	{
		UWorld* World = GetWorld();
		if (World != nullptr)
		{
			APlayerController* PlayerController = Cast<APlayerController>(Character->GetController());
			FRotator SpawnRotation = PlayerController->PlayerCameraManager->GetCameraRotation();
			FVector SpawnLocation = GetOwner()->GetActorLocation() + SpawnRotation.RotateVector(GuntipOffset);

			FActorSpawnParameters ActorSpawnParams;
			ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;
		
			World->SpawnActor<AActor>(ProjectileToSpawn, SpawnLocation, SpawnRotation, ActorSpawnParams);
		};
	};

	//Play sound
	if (ItemSound != nullptr)
	{
		UGameplayStatics::PlaySoundAtLocation(this, ItemSound, Character->GetActorLocation());
	};
	//Use >>Item<<
	if (ItemAnimation!=nullptr)
	{
		UAnimInstance* AnimInstance = Character->GetMesh()->GetAnimInstance();
		if (AnimInstance != nullptr)
		{
			AnimInstance->Montage_Play(ItemAnimation, 1.0f);
		}
	}

}
<<<<<<< HEAD

void UBaselinePickup::StopUse()
{
	FVector Location = GetComponentLocation();
	FRotator Rotation = GetComponentRotation();

	FActorSpawnParameters ActorSpawnParams;
	ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;

	GetWorld()->SpawnActor<AActor>(Respawn,Location,Rotation,ActorSpawnParams);

}
=======
>>>>>>> PlayercharacterFixes
