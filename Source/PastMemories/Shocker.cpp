// Sahraei.dev


#include "Shocker.h"

#include "CharacterBase.h"
#include "DrawDebugHelpers.h"
#include "HealthComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"

void AShocker::Use()
{
	Super::Use();
	UGameplayStatics::PlaySoundAtLocation(this,HittingSound,ParticlePlace->GetComponentLocation());
	FHitResult HitRes;
	CheckForEnemy(HitRes,Range);
	if(Cast<ACharacterBase>(HitRes.Actor))
	{
		Char = Cast<ACharacterBase>(HitRes.Actor);
		InitialWS = Char->GetCharacterMovement()->MaxWalkSpeed;
		Char->FindComponentByClass<UHealthComponent>()->AddDamage(DamageAmount);
		Char->GetCharacterMovement()->MaxWalkSpeed = StunWalkSpeed;
		FTimerHandle Timer;
		GetWorldTimerManager().SetTimer(Timer,this,&AShocker::Stun,StunDelay);
		Char->LaunchCharacter((GetOwner()->GetActorForwardVector() * Push) + GetOwner()->GetActorLocation(),true,true);
	}
}

void AShocker::Stun()
{
	Char->GetCharacterMovement()->MaxWalkSpeed = InitialWS;
}

