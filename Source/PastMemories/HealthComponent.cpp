// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"

#include "CharacterBase.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UHealthComponent::AddDamage(float Amount)
{
	if(Amount > 0)
	{
		UGameplayStatics::SpawnEmitterAtLocation(this,Cast<ACharacterBase>(GetOwner())->OnHitted,GetOwner()->GetActorLocation());
    	UGameplayStatics::PlaySoundAtLocation(this,Cast<ACharacterBase>(GetOwner())->HitSound,GetOwner()->GetActorLocation());
	}else if(Amount < 0)
	{
		UGameplayStatics::PlaySoundAtLocation(this,Cast<ACharacterBase>(GetOwner())->HealedSound,GetOwner()->GetActorLocation());
	}
	CurrentHealth = CurrentHealth + Amount;
	CurrentHealth = FMath::Clamp(CurrentHealth,0.f,MaxHealth);
	if(CurrentHealth == MaxHealth)
	{
		KillPlayer();
	}
}

void UHealthComponent::KillPlayer()
{
	if(ACharacterBase* CH = Cast<ACharacterBase>(GetOwner()))
	{
		CH->Killed();
	}
}



void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                     FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}
