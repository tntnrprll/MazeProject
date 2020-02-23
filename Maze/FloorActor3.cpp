// Fill out your copyright notice in the Description page of Project Settings.


#include "FloorActor3.h"

AFloorActor3::AFloorActor3()
{
	static ConstructorHelpers::FObjectFinder<UPaperSprite> FLOOR3(TEXT("PaperSprite'/Game/Image/Floor3_Sprite.Floor3_Sprite'"));
	if (FLOOR3.Succeeded())
	{
		Floor->SetSprite(FLOOR3.Object);
	}

	Collision->SetCollisionProfileName(TEXT("Team3Floor_Collision"));

	bReplicates = true;
}