// Sahraei.dev

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTSerPlayerIsSpotted.generated.h"

/**
 * 
 */
UCLASS()
class PASTMEMORIES_API UBTSerPlayerIsSpotted : public UBTService_BlackboardBase
{
	GENERATED_BODY()
public:
	UBTSerPlayerIsSpotted();
private:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};
