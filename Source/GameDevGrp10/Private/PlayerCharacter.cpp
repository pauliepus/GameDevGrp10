// Fill out your copyright notice in the Description page of Project Settings.
//Based on PKs tutorial


#include "PlayerCharacter.h"

#include "EnhancedInputComponent.h"
#include "Components/InputComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InteractInterface.h"
#include "PickUpBasePoels.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	PlayerCamera->bUsePawnControlRotation = true;
	PlayerPauseCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("PauseCameraComponent)"));
	
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* SubSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			SubSystem->AddMappingContext(IMC, 0);
		}
	}

	APlayerController* APlayerCharacter = Cast<APlayerController>(Controller);
	if (APlayerCharacter)
	{
		if (APlayerCharacter->PlayerCameraManager)
		{
			APlayerCharacter->PlayerCameraManager->ViewPitchMin = -50.0f;
			APlayerCharacter->PlayerCameraManager->ViewPitchMax = 50.0f;
			APlayerCharacter->PlayerCameraManager->ViewYawMin = -90.0f;
			APlayerCharacter->PlayerCameraManager->ViewYawMax = 90.0f;
		}
	}
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{

	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	if (EnhancedInputComponent)
	{
		EnhancedInputComponent->BindAction(Looking, ETriggerEvent::Triggered, this, &APlayerCharacter::Look);
		EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Triggered, this, &APlayerCharacter::InteractWithObjects);
		EnhancedInputComponent->BindAction(WaveStart, ETriggerEvent::Triggered, this, &APlayerCharacter::StartWave);
	}

}

void APlayerCharacter::InteractWithObjects(const FInputActionValue& Value)
{
	FVector StartTrace = GetCameraComponent()->GetComponentLocation();
	FVector EndTrace = StartTrace + GetCameraComponent()->GetComponentRotation().Vector() * InteractRange;

	FHitResult HitResult;
	FCollisionQueryParams CollisionParams;
	CollisionParams.AddIgnoredActor(this);

	if(GetWorld()->LineTraceSingleByChannel(HitResult, StartTrace, EndTrace, ECC_Visibility, CollisionParams))
	{
		UE_LOG(LogTemp, Warning, TEXT("Hit: %s"), *HitResult.GetActor()->GetName());
		if (HitResult.GetActor()->Implements<UInteractInterface>())
		{
			IInteractInterface::Execute_Interact(HitResult.GetActor());
		}
	}
	DrawDebugLine(GetWorld(), StartTrace, EndTrace, FColor::Green, false, 3.f, 0, 2.f);
}

void APlayerCharacter::AttachComponentToPlayer(APlayerCharacter* TargetCharacter)
{
	Character = TargetCharacter;

	if(TargetCharacter == nullptr || TargetCharacter->GetHasWeapon())
	{
		return;
	}

	FAttachmentTransformRules AttachmentRules(EAttachmentRule::SnapToTarget, true);

	AttachToComponent(TargetCharacter->GetMesh(), AttachmentRules, FName(TEXT("WeaponSocket")));

	TargetCharacter->SetHasWeapon(true);

	APlayerController* PlayerController = Cast<APlayerController>(TargetCharacter->GetController());
	if(PlayerController)
	{
		if(UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(IMC, 1);
		}

		UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerController->InputComponent);

		if(EnhancedInputComponent)
		{
			EnhancedInputComponent->BindAction(FireAction, ETriggerEvent::Triggered, this, &APlayerCharacter::Fire);
		}
	}
}

void APlayerCharacter::SetHasWeapon(bool bHasNewWeapon)
{
	bHasWeapon = bHasNewWeapon;
}

bool APlayerCharacter::GetHasWeapon()
{
	return bHasWeapon;
}

void APlayerCharacter::Fire()
{
	if(ProjectileToSpawn != nullptr)
	{
		UWorld* World = GetWorld();
		if(World != nullptr)
		{
			APlayerController* PlayerController = Cast<APlayerController>(Character->GetController());
			FRotator SpawnRotation = PlayerController->PlayerCameraManager->GetCameraRotation();
			FVector SpawnLocation = GetOwner()->GetActorLocation();

			FActorSpawnParameters ActorSpawnParams;
			ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

			World->SpawnActor<AActor>(ProjectileToSpawn, SpawnLocation, SpawnRotation, ActorSpawnParams);
		}
	}
}


UCameraComponent* APlayerCharacter::GetCameraComponent() const
{
	return PlayerCamera;
}

void APlayerCharacter::SwitchCamera()
{
	if (PlayerCamera->IsActive()) 
	{
		PlayerCamera->Deactivate();
		PlayerPauseCamera->Activate();
	}
	else
	{
		PlayerPauseCamera->Deactivate();
		PlayerCamera->Activate();
	}
	APlayerController* APlayerCharacter = Cast<APlayerController>(Controller);
	APlayerCharacter->SetViewTarget(this);
}


void APlayerCharacter::Look(const FInputActionValue& Value)
{
	FVector2D LookAroundVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		AddControllerYawInput(-LookAroundVector.X);
		AddControllerPitchInput(LookAroundVector.Y);
	}
}


void APlayerCharacter::StartWave()
{
	if (WaveEnded)
		WaveEnded = false;
}

void APlayerCharacter::EndWave()
{
	WaveEnded = true;
}