// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperSpriteActor.h"
#include "Components/BoxComponent.h"
#include "Paper2D/Classes/PaperSprite.h"
#include "Paper2D/Classes/PaperSpriteComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Net/UnrealNetwork.h"
#include "Bomb.generated.h"

/**
 * 
 */
UCLASS()
class MAZE_API ABomb : public APaperSpriteActor
{
	GENERATED_BODY()

protected:
	ABomb();
	//void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:
	UPROPERTY(VisibleAnywhere)
		UBoxComponent* Collision;

	/*
	UPROPERTY(VisibleAnywhere)
		UPaperSprite* Bomb1;
	UPROPERTY(VisibleAnywhere)
		UPaperSprite* Bomb2;
	UPROPERTY(VisibleAnywhere)
		UPaperSprite* Bomb3;
	UPROPERTY(VisibleAnywhere)
		UPaperSprite* Bomb4;

protected:
	UPROPERTY(VisibleAnywhere, ReplicatedUsing = OnRep_OwnNumber)
		int32 OwnNumber;
	UFUNCTION()
		void OnRep_OwnNumber();

public:
	UFUNCTION(Server, Reliable, WithValidation)
		void ServerSetOwnNumber(int32 Number);
	bool ServerSetOwnNumber_Validate(int32 Number);
	void ServerSetOwnNumber_Implementation(int32 Number);

	*/
};
