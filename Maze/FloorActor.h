// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperSpriteActor.h"
#include "UObject/ConstructorHelpers.h"
#include "Paper2D/Classes/PaperSpriteComponent.h"
#include "Paper2D/Classes/PaperSprite.h"
#include "Components/BoxComponent.h"
#include "Net/UnrealNetwork.h"
#include "FloorActor.generated.h"

/**
 * 
 */
UCLASS()
class MAZE_API AFloorActor : public APaperSpriteActor
{
	GENERATED_BODY()

public:
	AFloorActor();
	virtual void BeginPlay() override;

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:
	UPROPERTY(VisibleAnywhere,Replicated, Category = FloorNumber)
		int32 FloorNumber;

protected:
	UPROPERTY(VisibleAnywhere)
		UPaperSpriteComponent* Floor;

	UPROPERTY(VisibleAnywhere)
		UBoxComponent* Collision;

protected:
	UPROPERTY(ReplicatedUsing=OnRep_IsActive)
		bool IsActive = true;
	UFUNCTION()
		void OnRep_IsActive();

public:
	UFUNCTION(Server, Reliable, WithValidation)
		void ServerSetIsActive();
	bool ServerSetIsActive_Validate();
	void ServerSetIsActive_Implementation();

};
