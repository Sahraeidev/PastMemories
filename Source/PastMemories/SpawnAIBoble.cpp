// Sahraei.dev


#include "SpawnAIBoble.h"

#include "CharacterBase.h"

void ASpawnAIBoble::OnUsed()
{
	Super::OnUsed();
	FTimerHandle Timer;
	GetWorldTimerManager().SetTimer(Timer,this,&ASpawnAIBoble::Spawn,SpawnDelay,true);
}

void ASpawnAIBoble::Spawn()
{
	FVector SpawnPoint = SpawnPoints[FMath::RandRange(0,SpawnPoints.Num()-1)]->GetActorLocation();
	GetWorld()->SpawnActor<ACharacterBase>(EnemyClass,SpawnPoint,FRotator(0,0,0));
}
