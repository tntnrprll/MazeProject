// Fill out your copyright notice in the Description page of Project Settings.


#include "MakeMazeActor.h"


AMakeMazeActor::AMakeMazeActor()
{

	GridRootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("GridRootComponent"));
	RootComponent = GridRootComponent;

	bReplicates = true;
}

void AMakeMazeActor::BeginPlay()
{
	Super::BeginPlay();
	GenerateGrid(10, 10, 620);
	WhoFloor(10);
	SpawnFloorActor();
}


void AMakeMazeActor::GenerateGrid(int InGridWidth, int InGridHeight, int InTileSize)
{
	GridMap.Empty();
	GridWidth = InGridWidth;
	GridHeight = InGridHeight;
	TileSize = InTileSize;
	for (int X = 0; X < InGridWidth; X++)
	{
		for (int Y = 0; Y < InGridHeight; Y++)
		{
			GridMap.Add(FVector2D(X, Y), nullptr);
			GridArray.Add(FVector2D(X, Y));
		}
	}
}

FVector AMakeMazeActor::ConvertGridIndexToWorldLocation(FVector2D InGridIndex)
{
	FVector GridLocation = GetActorLocation();
	float X = GridLocation.X;
	float Y = GridLocation.Y + InGridIndex.Y*TileSize;
	float Z = GridLocation.Z + InGridIndex.X*TileSize;
	

	return FVector(X, Y, Z);

}


FVector2D AMakeMazeActor::ConvertWorldIndexToWorldLocation(FVector InWorldLocation)
{
	FVector GridLocation = GetActorLocation();

	int X = FMath::RoundToInt((InWorldLocation.Y - GridLocation.Y) / TileSize);
	int Y = FMath::RoundToInt((InWorldLocation.Z - GridLocation.Z) / TileSize);

	return FVector2D(X, Y);
}

void AMakeMazeActor::SpawnFloorActor()
{
	if (Role == ROLE_Authority)
	{
		int i = 0;

		for (auto GridMapNum = GridMap.CreateIterator(); GridMapNum; ++GridMapNum)
		{
			FActorSpawnParameters SpawnParameter;

			Location = ConvertGridIndexToWorldLocation(GridMapNum.Key());

			if (WhoFloorResultArray[i] == 1)
			{
				AFloorActor* SpawnedActor = GetWorld()->SpawnActor<AFloorActor>(FloorActor1, Location, Rotation, SpawnParameter);
			}
			else if (WhoFloorResultArray[i] == 2)
			{
				AFloorActor* SpawnedActor = GetWorld()->SpawnActor<AFloorActor>(FloorActor2, Location, Rotation, SpawnParameter);
			}
			else if (WhoFloorResultArray[i] == 3)
			{
				AFloorActor* SpawnedActor = GetWorld()->SpawnActor<AFloorActor>(FloorActor3, Location, Rotation, SpawnParameter);
			}
			else if (WhoFloorResultArray[i] == 4)
			{
				AFloorActor* SpawnedActor = GetWorld()->SpawnActor<AFloorActor>(FloorActor4, Location, Rotation, SpawnParameter);
			}
			
			i++;

		}
	}

}

void AMakeMazeActor::WhoFloor(int Size)
{
	int32 Team1Place = (Size*Size) / 4;
	int32 Team2Place = (Size*Size) / 4;
	int32 Team3Place = (Size*Size) / 4;
	int32 Team4Place = (Size*Size) / 4;


	for (int32 i = 0; i < Size*Size; i++)
	{
		if (Team1Place > 0)
		{
			WhoFloorTemp.Add(1);
			Team1Place--;
		}
		else if (Team2Place > 0)
		{
			WhoFloorTemp.Add(2);
			Team2Place--;
		}
		else if (Team3Place > 0)
		{
			WhoFloorTemp.Add(3);
			Team3Place--;
		}
		else if (Team4Place > 0)
		{
			WhoFloorTemp.Add(4);
			Team4Place--;
		}
	}

	
	while (WhoFloorTemp.Num() > 0)
	{
		int32 temp = FMath::Rand() % WhoFloorTemp.Num();

		WhoFloorResultArray.Add(WhoFloorTemp[temp]);
		WhoFloorTemp.RemoveAt(temp);
	}


}



