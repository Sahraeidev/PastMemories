// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon.h"

#include "CharacterBase.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AWeapon::AWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	RootComponent = Capsule;
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	MeshComp->SetupAttachment(Capsule);
	ParticlePlace = CreateDefaultSubobject<USceneComponent>(TEXT("Particle Place"));
	ParticlePlace->SetupAttachment(MeshComp);
}

/*USES THE WEAPON*/
void AWeapon::Use()
{
	UGameplayStatics::SpawnEmitterAtLocation(this,OnPressed,ParticlePlace->GetComponentLocation());
}

void AWeapon::CheckForEnemy(FHitResult& HitRes, float Ranges)
{
	TArray<AActor*> IgnoreActor;
	IgnoreActor.Add(GetOwner());
	FVector Start = GetOwner()->GetActorLocation();
	FVector End = Start + (GetOwner()->GetActorRotation().Vector() * Ranges);
	FCollisionQueryParams Params;
	UKismetSystemLibrary::LineTraceSingle(this,Start,End,UEngineTypes::ConvertToTraceType(ECC_Visibility),false,IgnoreActor,EDrawDebugTrace::None,HitRes,true);
}

/*WHEN PLAYER STEPS ON THE WEAPON*/
void AWeapon::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	if(bisPickedUp){return;}
	if(ACharacterBase* Character = Cast<ACharacterBase>(OtherActor))
	{
		Character->SetWeapon(this);
		bisPickedUp = true;
	}
}

