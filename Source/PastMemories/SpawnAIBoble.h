// Sahraei.dev

#pragma once

#include "CoreMinimal.h"
#include "MemoryBoble.h"
#include "SpawnAIBoble.generated.h"

/**
 * 
 */
UCLASS()
class PASTMEMORIES_API ASpawnAIBoble : public AMemoryBoble
{
	GENERATED_BODY()
private:
	virtual void OnUsed() override;
	void Spawn();
	UPROPERTY(EditAnywhere)
		TArray<AActor*> SpawnPoints;
	UPROPERTY(EditAnywhere)
		TSubclassOf<class ACharacterBase> EnemyClass;
	UPROPERTY(EditAnywhere)
		float SpawnDelay = 2.f;
};
