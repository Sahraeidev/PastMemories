// Sahraei.dev

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTaskLaunch.generated.h"

/**
 * 
 */
UCLASS()
class PASTMEMORIES_API UBTTaskLaunch : public UBTTaskNode
{
	GENERATED_BODY()
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
