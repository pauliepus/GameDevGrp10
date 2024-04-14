// Fill out your copyright notice in the Description page of Project Settings.
//Based on PKs tutorial


#include "PlayerCharacter.h"

#include "EngineUtils.h"
#include "EnhancedInputComponent.h"
#include "Components/InputComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "WaveManager.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	
	PlayerCamera->bUsePawnControlRotation = true;


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
			APlayerCharacter->PlayerCameraManager->ViewPitchMin = -70.0f;
			APlayerCharacter->PlayerCameraManager->ViewPitchMax = 50.0f;
			APlayerCharacter->PlayerCameraManager->ViewYawMin = -90.0f;
			APlayerCharacter->PlayerCameraManager->ViewYawMax = 90.0f;
		}
	}

	GetWorldTimerManager().SetTimer(T_CountDown, this, &APlayerCharacter::CountDown, 1.0f, true, 1.0f);

	EquipWeapon();
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
		EnhancedInputComponent->BindAction(WaveStart, ETriggerEvent::Triggered, this, &APlayerCharacter::StartWave);
	}

}

void APlayerCharacter::EquipWeapon()
{
	APlayerController* pController = Cast<APlayerController>(GetController());

	const FRotator pRotation = pController->PlayerCameraManager->GetCameraRotation();
	const FVector pLocation = GetOwner()->GetActorLocation();

	FActorSpawnParameters pSpawnParams;
	pSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	AActor* pShotGun = GetWorld()->SpawnActor<AActor>(m_cShotGun, pLocation, pRotation, pSpawnParams);

}

void APlayerCharacter::CountDown()
{
	if(Seconds>0)
	{
		--Seconds;
		UE_LOG(LogTemp, Warning, TEXT("Seconds %f"), Seconds);
	}
	else
	{
		--Minutes;
		Seconds = 11.0f;
		UE_LOG(LogTemp, Warning, TEXT("Minutes %d"), Minutes);

		if(Minutes <= 0)
		{
			GetWorldTimerManager().ClearTimer(T_CountDown);
			Seconds = 0.0f;
			UE_LOG(LogTemp, Warning, TEXT("End of Wave"));
		}
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

void APlayerCharacter::StartWave()
{
	if (WaveEnded)
		WaveEnded = false;
}

void APlayerCharacter::EndWave()
{
	WaveEnded = true;
}
