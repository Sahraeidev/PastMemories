// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Weapon.generated.h"

UCLASS()
class PASTMEMORIES_API AWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeapon();

	virtual void Use();
	UPROPERTY(VisibleAnywhere)
	bool bisPickedUp = false;
protected:
	void CheckForEnemy(FHitResult& HitRes,float Ranges);
	UPROPERTY(EditAnywhere)
		float DamageAmount = 20.f;
	UPROPERTY(EditAnywhere)
		USceneComponent* ParticlePlace;
	UPROPERTY(EditAnywhere)
	USoundBase* HittingSound;
private:
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	UPROPERTY(EditAnywhere)
		UParticleSystem* OnPressed;
	UPROPERTY(EditAnywhere)
		class UCapsuleComponent* Capsule;
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* MeshComp;

	UPROPERTY(EditAnywhere)
		UTexture2D* ItemImage;

	
};
