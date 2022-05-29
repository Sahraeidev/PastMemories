// Sahraei.dev


#include "OpenDoorBoble.h"


void AOpenDoorBoble::BeginPlay()
{
	Super::BeginPlay();
	if(ActorToMove != nullptr)
	{
		FirstLocation = ActorToMove->GetActorLocation();
		Targetlocation = FirstLocation +AddedLocation;
	}
}

void AOpenDoorBoble::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if(bIsBeginUsed)
	{
		FVector CurrentLoc = FMath::VInterpConstantTo(ActorToMove->GetActorLocation(),Targetlocation,DeltaSeconds,Speed);
		ActorToMove->SetActorLocation(CurrentLoc);
		if(ActorToMove->GetActorLocation() == Targetlocation)
		{
			Destroy();
		}
	}
}
void AOpenDoorBoble::OnUsed()
{
	Super::OnUsed();
	bIsBeginUsed = true;
}
