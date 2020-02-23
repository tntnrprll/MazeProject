// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperSpriteActor.h"
#include "Components/BoxComponent.h"
#include "Paper2D/Classes/PaperSprite.h"
#include "Paper2D/Classes/PaperSpriteComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Net/UnrealNetwork.h"
#include "FloorActor.h"
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
	virtual void BeginPlay() override;
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:
	UPROPERTY(VisibleAnywhere)
		UBoxComponent* Collision;


protected:
	UPROPERTY(Replicated)
		int32 CountdownTime=5;

	void SetCountdownTime(int32 Number);

	void AdvanceTimer();
	void CountdownHasFinished();

	FTimerHandle CountdownTimerHandle;

protected:

	UPROPERTY(EditAnywhere)
		TSubclassOf<AFloorActor> FloorActor;

protected:
	UFUNCTION(Server, Reliable, WithValidation)
		void ServerSpawnFloor(FVector Location);
	bool ServerSpawnFloor_Validate(FVector Location);
	void ServerSpawnFloor_Implementation(FVector Location);

	void AttempToSpawnFloor(FVector Location);
	void SpawnFloor(FVector Location);


};
