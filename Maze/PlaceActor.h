// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperSpriteActor.h"
#include "UObject/ConstructorHelpers.h"
#include "Paper2D/Classes/PaperSpriteComponent.h"
#include "Paper2D/Classes/PaperSprite.h"
#include "Components/BoxComponent.h"
#include "Net/UnrealNetwork.h"
#include "PlaceActor.generated.h"

/**
 * 
 */
UCLASS()
class MAZE_API APlaceActor : public APaperSpriteActor
{
	GENERATED_BODY()
	

public:
	APlaceActor();
	virtual void BeginPlay() override;

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:
	UPROPERTY(VisibleAnywhere, ReplicatedUsing = OnRep_FloorNumber, Category = FloorNumber)
		int32 FloorNumber;

public:
	UFUNCTION()
		void SetFloorNumber(int32 Number);
	UFUNCTION()
		int32 GetFloorNumber();

protected:
	UPROPERTY(EditAnywhere)
		UPaperSprite* Floor1;
	UPROPERTY(EditAnywhere)
		UPaperSprite* Floor2;
	UPROPERTY(EditAnywhere)
		UPaperSprite* Floor3;
	UPROPERTY(EditAnywhere)
		UPaperSprite* Floor4;

	UPROPERTY(VisibleAnywhere)
		UPaperSpriteComponent* Floor;

	UPROPERTY(VisibleAnywhere)
		UBoxComponent* Collision;

public:
	UFUNCTION()
		void SetFloorColor();

	UFUNCTION()
		void OnRep_FloorNumber();

public:
	UFUNCTION(Server, Reliable, WithValidation)
		void ServerSetFloorNumber(int32 Number);
	bool ServerSetFloorNumber_Validate(int32 Number);
	void ServerSetFloorNumber_Implementation(int32 Number);
};
