// Sahraei.dev


#include "BTTaskShoot.h"

#include "AIController.h"
#include "CharacterBase.h"

UBTTaskShoot::UBTTaskShoot()
{
	NodeName = "Shoot";
}

EBTNodeResult::Type UBTTaskShoot::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);
	if(ACharacterBase* AIChar = Cast<ACharacterBase>(OwnerComp.GetAIOwner()->GetPawn()))
	{
		AIChar->Hit();
		return EBTNodeResult::Succeeded;
	}
	return EBTNodeResult::Aborted;
}
