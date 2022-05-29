// Sahraei.dev

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTaskShoot.generated.h"

/**
 * 
 */
UCLASS()
class PASTMEMORIES_API UBTTaskShoot : public UBTTaskNode
{
	GENERATED_BODY()
public:
	UBTTaskShoot();
private:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
