// Sahraei.dev


#include "OldManController.h"

#include "DreamGamemode.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"

void AOldManController::GameEnd(bool bIsWon)
{
	if(bIsWon == false)
	DisableInput(this);
	TArray<AActor*> ReturnedSpecs;
	UGameplayStatics::GetAllActorsOfClass(this,SpecClass,ReturnedSpecs);
	FTimerHandle TimerToNext;
	GetWorldTimerManager().SetTimer(TimerToNext,this,&APlayerController::RestartLevel,ReturnToMenuTimer);
	UUserWidget* LostScreen = CreateWidget(this,LoseScreen);
	LostScreen->AddToViewport();
	if(ReturnedSpecs.Num() > 0)
	{
		AActor* EndSpec = ReturnedSpecs[0];
		SetViewTargetWithBlend(EndSpec,EndScreenTimer,EViewTargetBlendFunction::VTBlend_Cubic);

	}
	if(bIsWon)
	{
		FTimerHandle Timer;
		GetWorldTimerManager().SetTimer(TimerToNext,this,&AOldManController::OpenLevel,ReturnToMenuTimer);
		UUserWidget* Won = CreateWidget(this,WonScreen);
		Won->AddToViewport();
		if(ReturnedSpecs.Num() > 0)
		{
			AActor* EndSpec = ReturnedSpecs[0];
			SetViewTargetWithBlend(EndSpec,EndScreenTimer,EViewTargetBlendFunction::VTBlend_Cubic);
		}
	}
}

void AOldManController::OpenLevel()
{
	if(Cast<ADreamGamemode>(UGameplayStatics::GetGameMode(this)))
		UGameplayStatics::OpenLevel(this,Cast<ADreamGamemode>(UGameplayStatics::GetGameMode(this))->WorldToOpen);
}
