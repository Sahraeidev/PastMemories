// Sahraei.dev


#include "BTSerPlayerIsSpotted.h"

#include "CharacterBase.h"
#include "FighterAICotroller.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Perception/PawnSensingComponent.h"

UBTSerPlayerIsSpotted::UBTSerPlayerIsSpotted()
{
	NodeName = "Is Player Spotted";
}


void UBTSerPlayerIsSpotted::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
	if(AFighterAICotroller* PC =Cast<AFighterAICotroller>(OwnerComp.GetAIOwner()))
	{
		APawn* Player = GetWorld()->GetFirstPlayerController()->GetPawn();
		ACharacterBase* OwnPlayer = Cast<ACharacterBase>(OwnerComp.GetAIOwner()->GetPawn());
		if(OwnPlayer->FindComponentByClass<UPawnSensingComponent>()->CouldSeePawn(Player))
		{
			OwnerComp.GetBlackboardComponent()->SetValueAsObject("PlayerLocation",Player);
		}else
		{
			OwnerComp.GetBlackboardComponent()->ClearValue("PlayerLocation");
		}
	}
}
