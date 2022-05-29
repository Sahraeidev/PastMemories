// Sahraei.dev

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "DreamGamemode.generated.h"

/**
 * 
 */
UCLASS()
class PASTMEMORIES_API ADreamGamemode : public AGameModeBase
{
	GENERATED_BODY()
public:
	void OnPawnDied(APawn* KilledPawn);
	void BeginPlay() override;
	void SpawnEnemy();
	void SpawnMemory();
	void SpawnWeapon();
	void PlayerWonGame(int32 CurrentBobles);
	FVector GetRandomLocation();
	UPROPERTY(EditAnywhere)
		FName WorldToOpen;
	UPROPERTY(EditDefaultsOnly)
		TArray<TSubclassOf<class ACharacterBase>> Enemyclasses;
	UPROPERTY(EditDefaultsOnly)
		TArray<TSubclassOf<class AMemoryBoble>> Memories;
	UPROPERTY(EditDefaultsOnly)
		TArray<TSubclassOf<class AWeapon>> Guns;
	UPROPERTY(EditDefaultsOnly)
		float EnemySpawnDelay = 5.f;
	UPROPERTY(EditDefaultsOnly)
		float WeaponSpawn = 10.f;
	UPROPERTY(EditDefaultsOnly)
		float MemorySpawn = 20.f;
	UPROPERTY(EditDefaultsOnly)
		FName SpawnPointTag;
	UPROPERTY(EditAnywhere,BlueprintReadOnly)
		int32 MaxBobles = 10;
	TArray<AActor*> Actors;
}; 
