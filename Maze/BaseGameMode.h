// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "UObject/ConstructorHelpers.h"
#include "BasePlayerController.h"
#include "BaseCharacter.h"
#include "Team1Character.h"
#include "Team2Character.h"
#include "Team3Character.h"
#include "Team4Character.h"
#include "Paper2D/Classes/PaperSprite.h"
#include "BaseGameMode.generated.h"

/**
 * 
 */
UCLASS()
class MAZE_API ABaseGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	ABaseGameMode();
	virtual void BeginPlay() override;
	void PostLogin(APlayerController* NewPlayer) override;

	int32 PlayerNumber = 1;

protected:
	UPROPERTY(EditAnywhere, Category = SpawnCharacter)
		TSubclassOf<ATeam1Character> Player1;
	UPROPERTY(EditAnywhere, Category = SpawnCharacter)
		TSubclassOf<ATeam2Character> Player2;
	UPROPERTY(EditAnywhere, Category = SpawnCharacter)
		TSubclassOf<ATeam3Character> Player3;
	UPROPERTY(EditAnywhere, Category = SpawnCharacter)
		TSubclassOf<ATeam4Character> Player4;



	
};
