// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapon.h"
#include "Sword.generated.h"

/**
 * 
 */
UCLASS()
class PASTMEMORIES_API ASword : public AWeapon
{
	GENERATED_BODY()
public:
	virtual void Use() override;
private:
	UPROPERTY(EditAnywhere)
		float Range = 50.f;
};
