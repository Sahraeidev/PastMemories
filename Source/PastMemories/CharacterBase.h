// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterBase.generated.h"

class AWeapon;
UCLASS()
class PASTMEMORIES_API ACharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACharacterBase();

public:	
	void Hit();
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void SetWeapon(AWeapon* Weapon);
	void Killed();
	void SetFirstWeapon();
	void SetHit();
	UPROPERTY(EditAnywhere,BlueprintReadOnly)
		int32 CurrentBobles = 0;
	UPROPERTY(EditAnywhere)
	UParticleSystem* OnHitted;
	UPROPERTY(EditAnywhere)
	USoundBase* HitSound;
	UPROPERTY(EditAnywhere)
	USoundBase* HealedSound;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
		bool bIsHit;
private:
	UPROPERTY(EditAnywhere)
		USkeletalMeshComponent* MeshComp;
	UPROPERTY(EditAnywhere)
		bool bCanSpawn = true;
	UPROPERTY(EditAnywhere,Category = Fighting)
		TSubclassOf<AWeapon> FirstWeapon;
	UPROPERTY(EditAnywhere)
		USceneComponent* WeaponPlace;

	UPROPERTY(EditAnywhere,Category = Fighting)
		float PunchRange = 50.f;
	UPROPERTY(EditAnywhere,Category = Fighting)
		float PunchDamage = 10.f;
	UPROPERTY(EditAnywhere)
		TSubclassOf<UCameraShakeBase> HitShake;
	
	AWeapon* CurrentWeapon;
	void Punch();
	void MoveForward(float Value);
	void MoveRight(float Value);
};
