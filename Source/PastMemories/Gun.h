// Sahraei.dev

#pragma once

#include "CoreMinimal.h"
#include "Sword.h"
#include "Gun.generated.h"

/**
 * 
 */
UCLASS()
class PASTMEMORIES_API AGun : public AWeapon
{
	GENERATED_BODY()
private:
	bool bCanUse = true;

	void BeginPlay() override;
	void Use() override;
	void Reload();
	UPROPERTY(EditAnywhere)
		int32 MaxBullet = 6;
	UPROPERTY(VisibleAnywhere)
		int32 Bullet = 6;
	UPROPERTY(EditAnywhere)
		float Reloadelay = 3.f;
	UPROPERTY(EditAnywhere)
		float Range =100.f;
	UPROPERTY(EditAnywhere)
		USoundBase* Reloading;
};
