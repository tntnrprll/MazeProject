// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "Net/UnrealNetwork.h"
#include "UObject/ConstructorHelpers.h"
#include "Paper2D/Classes/PaperFlipbook.h"
#include "Paper2D/Classes/PaperSprite.h"
#include "Paper2D/Classes/PaperFlipbookComponent.h"
#include "Team1Character.generated.h"

/**
 * 
 */
UCLASS()
class MAZE_API ATeam1Character : public ABaseCharacter
{
	GENERATED_BODY()

public:
	ATeam1Character();
	virtual void BeginPlay() override;
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:

	UPROPERTY(VisibleAnywhere,Replicated, Category = PlayerNumber)
		int32 PlayerNumber = 1;

public:

	UFUNCTION(BlueprintCallable)
		int32 GetPlayerNumber();


	
};
