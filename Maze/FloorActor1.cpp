// Fill out your copyright notice in the Description page of Project Settings.


#include "FloorActor1.h"

AFloorActor1::AFloorActor1()
{
	static ConstructorHelpers::FObjectFinder<UPaperSprite> FLOOR1(TEXT("PaperSprite'/Game/Image/Floor1_Sprite.Floor1_Sprite'"));
	if (FLOOR1.Succeeded())
	{
		Floor->SetSprite(FLOOR1.Object);
	}

	Collision->SetCollisionProfileName(TEXT("Team1Floor_Collision"));

	bReplicates = true;

}