// Sahraei.dev


#include "FighterAICotroller.h"

#include "CharacterBase.h"
#include "BehaviorTree/BlackboardComponent.h"

void AFighterAICotroller::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	RunBehaviorTree(BehaviorTree);
	GetBlackboardComponent()->SetValueAsVector("FirstLocation",GetPawn()->GetActorLocation());
	Cast<ACharacterBase>(GetPawn())->SetFirstWeapon();
}
