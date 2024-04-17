// Fill out your copyright notice in the Description page of Project Settings.


#include "AShotgun.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputAction.h"
#include "Components/CapsuleComponent.h"


//based on https://youtu.be/WzbKfoe4sYc

// Sets default values
AAShotgun::AAShotgun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	PrimaryActorTick.bStartWithTickEnabled = false;

	RootComponent = Shotgun_Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Shotgun_Mesh"));
	
	//attributes, mesh call

	Shotgun_Mesh->CastShadow = true;
	Shotgun_Mesh->bCastHiddenShadow = true;

	//attaching rootcomponent Possibly switch SKEL_ to SM_ idk
	Shotgun_Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(Text("Shotgun_Mesh"));
	Shotgun_Mesh->SetupAttachment(RootComponent);
	
	//Unnecessary?
	Shotgun_Mesh->SetOnlyOwnerSee(true);
	//Unnecessary?
	bReplicates = true;
}

void AAShotgun::Fire(const FInputActionValue& Value)
{
	if (Bullet)
		GetWorld()->SpawnActor<AActor>(UClass *Bullet, GetActorLocation(), GetActorRotation());

	UE_LOG(LogTemp, Warning, TEXT("FIRE"));
	
}

void AAShotgun::Fire2()
{
	if (Bullet != nullptr)
	{
		UWorld* World = GetWorld();
		if (World != nullptr)
		{
			APlayerController* PlayerController = Cast<APlayerController>(Character->GetController());
			FRotator SpawnRotation = PlayerController->PlayerCameraManager->GetCameraRotation();
			FVector SpawnLocation = GetOwner()->GetActorLocation();

			FActorSpawnParameters ActorSpawnParams;
			ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

			//I changed ProjectileToSpawn to Bullet, was that R-slur of me?
			//Do we instead use Projectile to spawn, which is "Bullet* ProjectileToSpawn" in bullet.h??
			World->SpawnActor<AActor>(Bullet, SpawnLocation, SpawnRotation, ActorSpawnParams);
		}
	}
}

/* CHECK THIS SHIT OUT https://forums.unrealengine.com/t/call-function-from-another-class/385683/4

void AFirstPersonCharacter::FunctionThatDoesStuff()
{
	for (TObjectIterator<AClass1> Itr; Itr; ++Itr)
	{
		if (Itr->IsA(AClass1::StaticClass()))
		{
			AClass1* actorClass = *Itr;
			actorClass->SpecialFunction();
		}
	}
}
*/
//solution 2 for calling classes outside of THIS class or whatever
// probly better solution
/*
void AFirstPersonCharacter::TestFunction()
{
	AClass1* actorClass = Cast<AClass1>(()->SpawnActor(AClass1::StaticClass())));
	// or shorter: AClass1* actorClass = ()->SpawnActor<AClass1>();

	actorClass->SpecialFunction();
}
*/

// Called when the game starts or when spawned
void AAShotgun::BeginPlay()
{
	Super::BeginPlay();
	
}



void PlayerCharacter::InteractWithObjects(AAShotgun* TargetCharacter)
{
	Character = TargetCharacter;

	if (TargetCharacter == nullptr || TargetCharacter->GetHasWeapon())
	{
		return;
	}

	FAttachmentTransformRules AttachmentRules(EAttachmentRule::SnapToTarget, true);

	AttachToComponent(TargetCharacter->GetMesh(), AttachmentRules, FName(TEXT("WeaponSocket")));

	TargetCharacter->SetHasWeapon(true);

	APlayerController* PlayerController = Cast<APlayerController>(TargetCharacter->GetController());
	if (PlayerController)
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(IMC, 1);
		}

		UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerController->InputComponent);

		if (EnhancedInputComponent)
		{
			EnhancedInputComponent->BindAction(FireAction, ETriggerEvent::Triggered, this, &APlayerCharacter::Fire);
		}
	}
}

void AAShotgun::SetHasWeapon(bool bHasNewWeapon)
{
	bHasWeapon = bHasNewWeapon;
}

bool AAShotgun::GetHasWeapon()
{
	return bHasWeapon;
}

void AAShotgun::Fire()
{
	if (ProjectileToSpawn != nullptr)
	{
		UWorld* World = GetWorld();
		if (World != nullptr)
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