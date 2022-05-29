 // Sahraei.dev


#include "BTTaskLaunch.h"

#include "AIController.h"
#include "GameFramework/Character.h"

 EBTNodeResult::Type UBTTaskLaunch::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
 {
	Super::ExecuteTask(OwnerComp, NodeMemory);
 	ACharacter* Char = Cast<ACharacter>(OwnerComp.GetAIOwner()->GetPawn());
 	Char->Jump();

 	return EBTNodeResult::Succeeded;
 }
