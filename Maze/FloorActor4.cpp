// Fill out your copyright notice in the Description page of Project Settings.


#include "FloorActor4.h"

AFloorActor4::AFloorActor4()
{
	static ConstructorHelpers::FObjectFinder<UPaperSprite> FLOOR4(TEXT("PaperSprite'/Game/Image/Floor4_Sprite.Floor4_Sprite'"));
	if (FLOOR4.Succeeded())
	{
		Floor->SetSprite(FLOOR4.Object);
	}

	Collision->SetCollisionProfileName(TEXT("Team4Floor_Collision"));

	bReplicates = true;
}