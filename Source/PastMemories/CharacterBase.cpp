// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterBase.h"
#include "DrawDebugHelpers.h"
#include "DreamGamemode.h"
#include "HealthComponent.h"
#include "Weapon.h"

// Sets default values
ACharacterBase::ACharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	WeaponPlace = CreateDefaultSubobject<USceneComponent>(TEXT("Holder"));
	WeaponPlace->SetupAttachment(GetRootComponent());
}

void ACharacterBase::SetFirstWeapon()
{
	if(FirstWeapon)
	{
		AWeapon* Weapon = GetWorld()->SpawnActor<AWeapon>(FirstWeapon,WeaponPlace->GetComponentLocation(),WeaponPlace->GetComponentRotation());
		UE_LOG(LogTemp,Warning,TEXT("%s"),*Weapon->GetName());
		Weapon->bisPickedUp = true;
		CurrentWeapon = Weapon;
		CurrentWeapon->SetOwner(this);

	}
}

void ACharacterBase::SetHit()
{
	bIsHit = false;
}

//Called to bind functionality to input
void ACharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward",this,&ACharacterBase::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight",this,&ACharacterBase::MoveRight);
	PlayerInputComponent->BindAxis("Rotate",this,&APawn::AddControllerYawInput);
	PlayerInputComponent->BindAction("Hit",IE_Pressed,this,&ACharacterBase::Hit);
	PlayerInputComponent->BindAction("Jump",IE_Pressed,this,&ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump",IE_Released,this,&ACharacter::StopJumping);
}

/*SETS THE CURRENT WEAPON*/
void ACharacterBase::SetWeapon(AWeapon* Weapon)
{
	MeshComp = FindComponentByClass<USkeletalMeshComponent>();
	Weapon->bisPickedUp = true;
	if(CurrentWeapon != nullptr)
	{
		CurrentWeapon->Destroy();
	}
	CurrentWeapon = Weapon;
	CurrentWeapon->SetActorLocation(WeaponPlace->GetComponentLocation());
	CurrentWeapon->SetOwner(this);
	CurrentWeapon->AttachToComponent(MeshComp,FAttachmentTransformRules::SnapToTargetNotIncludingScale,"GunPlace");
}

/*PUNCHES*/
void ACharacterBase::Punch()
{
	FHitResult HitRes;
	FVector Start = WeaponPlace->GetComponentLocation();
	FVector End = Start + (GetActorRotation().Vector() * PunchRange);
	FCollisionQueryParams Params;
	GetWorld()->LineTraceSingleByChannel(HitRes,Start,End,ECC_Visibility,Params);
	if(ACharacterBase* Target = Cast<ACharacterBase>(HitRes.Actor))
	{
		Target->FindComponentByClass<UHealthComponent>()->AddDamage(PunchDamage);
	}
}

/*HIT*/
void ACharacterBase::Hit()
{
	FTimerHandle Timer;
	GetWorldTimerManager().SetTimer(Timer,this,&ACharacterBase::SetHit,0.4f);
	bIsHit = true;
	if(CurrentWeapon != nullptr)
	{
		CurrentWeapon->Use();
	}
	else
	{
		Punch();
	}
}

/*MOVEMENT*/
void ACharacterBase::MoveForward(float Value)
{
	AddMovementInput(GetActorForwardVector(),Value);
}
void ACharacterBase::MoveRight(float Value)
{
	AddMovementInput(GetActorRightVector(),Value);
}

/*ON PLAYER KILLED*/
void ACharacterBase::Killed()
{
	if(CurrentWeapon)
		CurrentWeapon->Destroy();
		
	if(ADreamGamemode* Gamemode = Cast<ADreamGamemode>(GetWorld()->GetAuthGameMode()))
	{
		Gamemode->OnPawnDied(this);
		if(bCanSpawn)
		{
			FVector SpawnLoc = GetActorLocation() + FVector(0,0,40);
			if(FirstWeapon)
			{
				AWeapon* WeaponDrop = GetWorld()->SpawnActor<AWeapon>(FirstWeapon,SpawnLoc,FRotator(0,0,0));
				WeaponDrop->bisPickedUp = false;
			}
		}
	}
}
