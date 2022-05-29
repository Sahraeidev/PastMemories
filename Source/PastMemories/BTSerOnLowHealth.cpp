// Sahraei.dev


#include "BTSerOnLowHealth.h"

#include "AIController.h"
#include "HealthComponent.h"
#include "MemoryBoble.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"

void UBTSerOnLowHealth::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
	if(UHealthComponent* HealthComp = OwnerComp.GetAIOwner()->GetPawn()->FindComponentByClass<UHealthComponent>())
	{
		AActor* HealPoint = UGameplayStatics::GetActorOfClass(this,AMemoryBoble::StaticClass());
		if(HealPoint == nullptr)
		{return;}
		if(HealthComp->GetHealth() > 90.f)
		{
			OwnerComp.GetAIOwner()->GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(),HealPoint->GetActorLocation());
		}else
		{
			OwnerComp.GetAIOwner()->GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());
		}
	}

}
