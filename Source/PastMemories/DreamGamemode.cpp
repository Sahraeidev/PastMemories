// Sahraei.dev


#include "DreamGamemode.h"

#include "CharacterBase.h"
#include "MemoryBoble.h"
#include "OldManController.h"
#include "Weapon.h"
#include "Kismet/GameplayStatics.h"



void ADreamGamemode::BeginPlay()
{
	Super::BeginPlay();
	FTimerHandle WeaponTimer;
	FTimerHandle MemoryTimer;
	FTimerHandle EnemyTimer;
	GetWorldTimerManager().SetTimer(MemoryTimer,this,&ADreamGamemode::SpawnMemory,MemorySpawn,true);
	GetWorldTimerManager().SetTimer(WeaponTimer,this,&ADreamGamemode::SpawnWeapon,WeaponSpawn,true);
	GetWorldTimerManager().SetTimer(EnemyTimer,this,&ADreamGamemode::SpawnEnemy,EnemySpawnDelay,true);
	UGameplayStatics::GetAllActorsWithTag(this,SpawnPointTag,Actors);
}


/*ON PAWN GETTING KILLED*/
void ADreamGamemode::OnPawnDied(APawn* KilledPawn)
{
	KilledPawn->DisableInput(nullptr);
	if(KilledPawn == UGameplayStatics::GetPlayerPawn(this,0))
	{
		if(AOldManController* PC = Cast<AOldManController>(UGameplayStatics::GetPlayerController(this,0)))
		{
		    
			PC->GameEnd(false);
		}
	}else
	{
		KilledPawn->Destroy();
	}
	
}

void ADreamGamemode::SpawnEnemy()
{
	int32 randomnum = FMath::RandRange(0,Enemyclasses.Num() - 1);
	GetWorld()->SpawnActor<ACharacterBase>(Enemyclasses[randomnum],GetRandomLocation(),FRotator(0,0,0));
}
void ADreamGamemode::SpawnMemory()
{
	int32 randomnum = FMath::RandRange(0,Memories.Num() - 1);
	GetWorld()->SpawnActor<AMemoryBoble>(Memories[randomnum],GetRandomLocation(),FRotator(0,0,0));
}
void ADreamGamemode::SpawnWeapon()
{
	int32 randomnum = FMath::RandRange(0,Guns.Num() - 1);
	GetWorld()->SpawnActor<AWeapon>(Guns[randomnum],GetRandomLocation(),FRotator(0,0,0));

}
FVector ADreamGamemode::GetRandomLocation()
{
	int32 randomnum = FMath::RandRange(0,Actors.Num() - 1);
	return Actors[randomnum]->GetActorLocation();
}

void ADreamGamemode::PlayerWonGame(int32 CurrentBobles)
{
	if(CurrentBobles == MaxBobles)
	{
		if(AOldManController* PC = Cast<AOldManController>(UGameplayStatics::GetPlayerController(this,0)))
		{
		    
			PC->GameEnd(true);
		}
	}
}
