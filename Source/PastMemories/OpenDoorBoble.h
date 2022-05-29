// Sahraei.dev

#pragma once

#include "CoreMinimal.h"
#include "MemoryBoble.h"
#include "OpenDoorBoble.generated.h"

/**
 * 
 */
UCLASS()
class PASTMEMORIES_API AOpenDoorBoble : public AMemoryBoble
{
	GENERATED_BODY()
private:
	virtual void OnUsed() override;
	void BeginPlay() override;
	void Tick(float DeltaSeconds) override;
	bool bIsBeginUsed = false;
	FVector FirstLocation;
	FVector Targetlocation;
	UPROPERTY(EditAnywhere)
		FVector AddedLocation;
	UPROPERTY(EditAnywhere)
		float Speed;
	UPROPERTY(EditAnywhere)
		AActor* ActorToMove;
};
