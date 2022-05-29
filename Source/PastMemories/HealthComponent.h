// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Character.h"
#include "HealthComponent.generated.h"

class ACharacterBase;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PASTMEMORIES_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();
	UFUNCTION(BlueprintCallable)
		void AddDamage(float Amount);
	
	void KillPlayer();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UFUNCTION(BlueprintCallable)
		FORCEINLINE float GetMaxHealth(){return MaxHealth;}
	UFUNCTION(BlueprintCallable)
		FORCEINLINE float GetHealth(){return CurrentHealth;}
private:

	UPROPERTY(EditAnywhere,Category=Health)
		float MaxHealth = 100.f;
	UPROPERTY(VisibleAnywhere,Category=Health)
		float CurrentHealth = 0.f;

};
