// Sahraei.dev

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTSerOnLowHealth.generated.h"

/**
 * 
 */
UCLASS()
class PASTMEMORIES_API UBTSerOnLowHealth : public UBTService_BlackboardBase
{
	GENERATED_BODY()
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};
