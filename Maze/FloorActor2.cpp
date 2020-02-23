// Fill out your copyright notice in the Description page of Project Settings.


#include "FloorActor2.h"

AFloorActor2::AFloorActor2()
{
	static ConstructorHelpers::FObjectFinder<UPaperSprite> FLOOR2(TEXT("PaperSprite'/Game/Image/Floor2_Sprite.Floor2_Sprite'"));
	if (FLOOR2.Succeeded())
	{
		Floor->SetSprite(FLOOR2.Object);
	}

	Collision->SetCollisionProfileName(TEXT("Team2Floor_Collision"));

	bReplicates = true;
}