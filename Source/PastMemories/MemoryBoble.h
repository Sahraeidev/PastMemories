// Sahraei.dev

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MemoryBoble.generated.h"

UCLASS()
class PASTMEMORIES_API AMemoryBoble : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMemoryBoble();
protected:
	virtual void OnUsed();
private:
	void NotifyActorBeginOverlap(AActor* OtherActor) override;
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* Mesh;
	UPROPERTY(EditAnywhere)
		float AdeddHealth = 20.f;
	UPROPERTY(EditAnywhere)
		UParticleSystem* OnMemoryAdded;
};
