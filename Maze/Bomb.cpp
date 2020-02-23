
// Fill out your copyright notice in the Description page of Project Settings.


#include "Bomb.h"

ABomb::ABomb()
{
	Collision = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision"));
	Collision->SetupAttachment(RootComponent);
	Collision->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	Collision->SetRelativeScale3D(FVector(1.0f, 1.0f, 1.0f));
	
	/*
	static ConstructorHelpers::FObjectFinder<UPaperSprite> BOMB1(TEXT("PaperSprite'/Game/Image/Bomb1_Sprite.Bomb1_Sprite'"));
	if (BOMB1.Succeeded())
	{
		Bomb1=BOMB1.Object ;
	}
	static ConstructorHelpers::FObjectFinder<UPaperSprite> BOMB2(TEXT("PaperSprite'/Game/Image/Bomb2_Sprite.Bomb2_Sprite'"));
	if (BOMB2.Succeeded())
	{
		Bomb2 = BOMB2.Object;
	}
	static ConstructorHelpers::FObjectFinder<UPaperSprite> BOMB3(TEXT("PaperSprite'/Game/Image/Bomb3_Sprite.Bomb3_Sprite'"));
	if (BOMB3.Succeeded())
	{
		Bomb3 = BOMB3.Object;
	}
	static ConstructorHelpers::FObjectFinder<UPaperSprite> BOMB4(TEXT("PaperSprite'/Game/Image/Bomb4_Sprite.Bomb4_Sprite'"));
	if (BOMB4.Succeeded())
	{
		Bomb4 = BOMB4.Object;
	}
	*/

}
/*
void ABomb::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ABomb, OwnNumber);


}

bool ABomb::ServerSetOwnNumber_Validate(int32 Number)
{
	return true;
}

void ABomb::ServerSetOwnNumber_Implementation(int32 Number)
{
	if (Role = ROLE_Authority)
	{
		OwnNumber = Number;
		OnRep_OwnNumber();
	}
}

void ABomb::OnRep_OwnNumber()
{
	switch (OwnNumber)
	{
	case 1:
		GetRenderComponent()->SetSprite(Bomb1);
		break;

	case 2:
		GetRenderComponent()->SetSprite(Bomb2);
		break;

	case 3:
		GetRenderComponent()->SetSprite(Bomb3);
		break;

	case 4:
		GetRenderComponent()->SetSprite(Bomb4);
		break;

	default:

	}
}
*/
