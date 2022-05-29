// Sahraei.dev

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "FighterAICotroller.generated.h"

/**
 * 
 */
UCLASS()
class PASTMEMORIES_API AFighterAICotroller : public AAIController
{
	GENERATED_BODY()
private:
	virtual void OnPossess(APawn* InPawn) override;
	UPROPERTY(EditAnywhere)
		class UBehaviorTree* BehaviorTree;
};
