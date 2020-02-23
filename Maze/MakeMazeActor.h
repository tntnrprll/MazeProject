// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperSpriteActor.h"
#include "FloorActor.h"
#include "Engine/World.h"
#include "MakeMazeActor.generated.h"


/**
 * 
 */
UCLASS()
class MAZE_API AMakeMazeActor : public APaperSpriteActor
{
	GENERATED_BODY()

public:
	AMakeMazeActor();
	virtual void BeginPlay() override;
	
public:
	void GenerateGrid(int InGridWidth, int InGridHeight, int InTileSize);

	FVector ConvertGridIndexToWorldLocation(FVector2D InGridIndex);
	FVector2D ConvertWorldIndexToWorldLocation(FVector InWorldLocation);

	UPROPERTY(VisibleAnywhere)
		FVector Location;
	UPROPERTY(VisibleAnywhere)
		FRotator Rotation;

public:


	/************甘 积己**************/

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		USceneComponent* GridRootComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		TMap<FVector2D, UStaticMeshComponent*> GridMap;
	
	UPROPERTY(VisibleAnywhere)
		TArray<FVector2D> GridArray;
	UPROPERTY(VisibleAnywhere)
		int GridWidth;
	UPROPERTY(VisibleAnywhere)
		int GridHeight;
	int TileSize = 100;

	UPROPERTY(EditAnywhere, Category = SpawnObject)
		TSubclassOf<AFloorActor> FloorActor1;
	UPROPERTY(EditAnywhere, Category = SpawnObject)
		TSubclassOf<AFloorActor> FloorActor2;
	UPROPERTY(EditAnywhere, Category = SpawnObject)
		TSubclassOf<AFloorActor> FloorActor3;
	UPROPERTY(EditAnywhere, Category = SpawnObject)
		TSubclassOf<AFloorActor> FloorActor4;



	UFUNCTION()
		void SpawnFloorActor();

public:

	/******************家蜡 郴侩 积己*******************/
	TArray<int32> WhoFloorTemp;
	TArray<int32> WhoFloorResultArray;

	UPROPERTY(VisibleAnywhere)
		int MazeSize;

	void WhoFloor(int MazeSize);

};
