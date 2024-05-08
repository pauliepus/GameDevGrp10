// Fill out your copyright notice in the Description page of Project Settings.
//Based on PKs tutorial


#include "PlayerCharacter.h"

#include "EnhancedInputComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InteractInterface.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//camera (?)
	PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	PlayerCamera->bUsePawnControlRotation = true;
	
	MeshFPV = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharMesh"));
	MeshFPV->SetupAttachment(PlayerCamera);
	
	/* Additional cameras for CameraSwitching*/
	ForestCam1 = CreateDefaultSubobject<UCameraComponent>(TEXT("ForestCam1"));
	ForestCam2 = CreateDefaultSubobject<UCameraComponent>(TEXT("ForestCam2"));
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

	ForestCam1->Deactivate();
	ForestCam2->Deactivate();
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
		EnhancedInputComponent->BindAction(StartWaveAction, ETriggerEvent::Triggered, this, &APlayerCharacter::StartWave);
		EnhancedInputComponent->BindAction(SwitchViewAction, ETriggerEvent::Started, this, &APlayerCharacter::SwitchView);
	}

}

//Ray from player to stuck

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
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("Sadge %p"), HitResult.GetActor()));
		if (HitResult.GetActor()->Implements<UInteractInterface>())
		{

			if (GEngine)
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("Freedom is close ")));

			IInteractInterface::Execute_Interact(HitResult.GetActor());
 
		}
	}
	DrawDebugLine(GetWorld(), StartTrace, EndTrace, FColor::Green, false, 3.f, 0, 2.f);
}

/*
* Fire function  (working)
*/

void APlayerCharacter::Fire()
{
	if (ProjectileToSpawn != nullptr)
	{
		UWorld* World = GetWorld();
		if (World != nullptr)
		{
			APlayerController* PlayerController = Cast<APlayerController>(FireCharacter->GetController());
			FRotator SpawnRotation = PlayerController->PlayerCameraManager->GetCameraRotation();
			FVector SpawnLocation = GetOwner()->GetActorLocation();

			FActorSpawnParameters ActorSpawnParams;
			ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

			World->SpawnActor<AActor>(ProjectileToSpawn, SpawnLocation, SpawnRotation, ActorSpawnParams);
		}
	}

	if (FireSound != nullptr)
	{
		UGameplayStatics::PlaySoundAtLocation(this, FireSound, FireCharacter->GetActorLocation());
	}
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

void APlayerCharacter::SwitchView()
{
	if (PlayerCamera->IsActive())
	{
		ForestCam1->Activate();
		PlayerCamera->Deactivate();
		if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
			PlayerController->SetIgnoreLookInput(true);
	}
	else if (ForestCam1->IsActive())
	{
		ForestCam2->Activate();
		ForestCam1->Deactivate();
	}
	else
	{
		PlayerCamera->Activate();
		ForestCam2->Deactivate();
		if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
			PlayerController->SetIgnoreLookInput(false);
	}
}

UCameraComponent* APlayerCharacter::GetCameraComponent() const
{
	return PlayerCamera;
}

//get mesh from thing u pickup firstpersonview

USkeletalMeshComponent* APlayerCharacter::GetMeshFPV() const
{
	return MeshFPV;
}

/*
* bools for Lighter
*/

void APlayerCharacter::SetHasLighter(bool HasLighter)
{
	bHasLighter = true;
}

bool APlayerCharacter::GetHasLighter()
{
	return bHasLighter;
}
//end

/*
* bools for Waves
*/

void APlayerCharacter::StartWave()
{
	if (WaveEnded)
		WaveEnded = false;
}

void APlayerCharacter::EndWave()
{
	WaveEnded = true;
}

