// Sahraei.dev

#pragma once

#include "CoreMinimal.h"
#include "Weapon.h"
#include "Shocker.generated.h"

/**
 * 
 */
UCLASS()
class PASTMEMORIES_API AShocker : public AWeapon
{
	GENERATED_BODY()
private:
	virtual void Use() override;
	void Stun();
	class ACharacterBase* Char;
	float InitialWS;
	
	UPROPERTY(EditAnywhere)
		float Push = 30.f;
	UPROPERTY(EditAnywhere)
		float StunWalkSpeed = 3.f;
	UPROPERTY(EditAnywhere)
		float StunDelay = 3.f;
	UPROPERTY(EditAnywhere)
		float Range = 50.f;
};
