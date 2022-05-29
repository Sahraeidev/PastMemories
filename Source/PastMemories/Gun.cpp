// Sahraei.dev


#include "Gun.h"
#include "CharacterBase.h"
#include "DrawDebugHelpers.h"
#include "HealthComponent.h"
#include "Kismet/GameplayStatics.h"


void AGun::BeginPlay()
{
	Super::BeginPlay();
	Bullet = MaxBullet;
}

/*USES THE ITEM*/
void AGun::Use()
{
	Super::Use();
	if(bCanUse == false){return;}
	FHitResult HitRes;
	CheckForEnemy(HitRes,Range);
	if(ACharacterBase* Char = Cast<ACharacterBase>(HitRes.Actor))
	{
		Char->FindComponentByClass<UHealthComponent>()->AddDamage(DamageAmount);
		
	}
	Bullet--;
	if(Bullet == 0)
	{
		FTimerHandle Timer;
		UGameplayStatics::PlaySoundAtLocation(this,Reloading,ParticlePlace->GetComponentLocation());
		GetWorldTimerManager().SetTimer(Timer,this,&AGun::Reload,Reloadelay);
		bCanUse = false;
	}else
	{
		UGameplayStatics::PlaySoundAtLocation(this,HittingSound,ParticlePlace->GetComponentLocation());
	}
}

/*RELOADS*/
void AGun::Reload()
{
	Bullet = MaxBullet;
	bCanUse = true;
}

