// Sahraei.dev


#include "MemoryBoble.h"

#include "CharacterBase.h"
#include "DreamGamemode.h"
#include "HealthComponent.h"
#include "Kismet/GameplayStatics.h"

AMemoryBoble::AMemoryBoble()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	RootComponent = Mesh;
}

/*ON GETTING MEMORY*/
void AMemoryBoble::OnUsed()
{
	Destroy();
}

/*ON OVERLAP MEMORY*/
void AMemoryBoble::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	
	ACharacterBase* player = Cast<ACharacterBase>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if(player && OtherActor == player)
	{
	    OnUsed();
		UGameplayStatics::SpawnEmitterAtLocation(this,OnMemoryAdded,GetActorLocation());
    	Mesh->SetHiddenInGame(true);
		player->CurrentBobles++;
		if(Cast<ADreamGamemode>(UGameplayStatics::GetGameMode(this)))
			Cast<ADreamGamemode>(UGameplayStatics::GetGameMode(this))->PlayerWonGame(player->CurrentBobles);
	}
	if(OtherActor->FindComponentByClass<UHealthComponent>())
		OtherActor->FindComponentByClass<UHealthComponent>()->AddDamage(-AdeddHealth);
}

