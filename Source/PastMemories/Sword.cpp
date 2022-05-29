// Fill out your copyright notice in the Description page of Project Settings.


#include "Sword.h"
#include "CharacterBase.h"
#include "DrawDebugHelpers.h"
#include "HealthComponent.h"
#include "Kismet/GameplayStatics.h"

void ASword::Use()
{
	Super::Use();
	UGameplayStatics::PlaySoundAtLocation(this,HittingSound,ParticlePlace->GetComponentLocation());
	FHitResult HitRes;
	CheckForEnemy(HitRes,Range);
	if(ACharacterBase* Char = Cast<ACharacterBase>(HitRes.Actor))
	{
		Char->FindComponentByClass<UHealthComponent>()->AddDamage(DamageAmount);
	}
}
