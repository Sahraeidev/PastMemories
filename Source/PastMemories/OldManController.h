// Sahraei.dev

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "OldManController.generated.h"

/**
 * 
 */
UCLASS()
class PASTMEMORIES_API AOldManController : public APlayerController
{
	GENERATED_BODY()
public:
	void GameEnd(bool bIsWon);
private:
	void OpenLevel();
	
	UPROPERTY(EditAnywhere)
	float EndScreenTimer = 3.f;
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AActor> SpecClass;
	UPROPERTY(EditAnywhere)
	float ReturnToMenuTimer = 5.f;
	UPROPERTY(EditAnywhere)
		TSubclassOf<UUserWidget> LoseScreen;
	UPROPERTY(EditAnywhere)
		TSubclassOf<UUserWidget> WonScreen;
};
