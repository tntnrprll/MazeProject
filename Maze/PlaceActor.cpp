// Fill out your copyright notice in the Description page of Project Settings.


#include "PlaceActor.h"


APlaceActor::APlaceActor()
{
	static ConstructorHelpers::FObjectFinder<UPaperSprite> FLOOR1(TEXT("PaperSprite'/Game/Image/Floor1_Sprite.Floor1_Sprite'"));
	if (FLOOR1.Succeeded())
	{
		Floor1 = FLOOR1.Object;
	}
	static ConstructorHelpers::FObjectFinder<UPaperSprite> FLOOR2(TEXT("PaperSprite'/Game/Image/Floor2_Sprite.Floor2_Sprite'"));
	if (FLOOR2.Succeeded())
	{
		Floor2 = FLOOR2.Object;
	}
	static ConstructorHelpers::FObjectFinder<UPaperSprite> FLOOR3(TEXT("PaperSprite'/Game/Image/Floor3_Sprite.Floor3_Sprite'"));
	if (FLOOR3.Succeeded())
	{
		Floor3 = FLOOR3.Object;
	}
	static ConstructorHelpers::FObjectFinder<UPaperSprite> FLOOR4(TEXT("PaperSprite'/Game/Image/Floor4_Sprite.Floor4_Sprite'"));
	if (FLOOR4.Succeeded())
	{
		Floor4 = FLOOR4.Object;
	}


	Floor = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("Floor"));
	Floor->SetupAttachment(Collision);
	Floor->SetRelativeRotation(FRotator(0.0f, 90.0f, 0.0f));
	Floor->SetSprite(Floor1);
	Floor->SetCollisionProfileName(TEXT("NoCollision"));

	Collision = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision"));
	Collision->SetupAttachment(RootComponent);
	Collision->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	Collision->SetRelativeScale3D(FVector(5.0f, 5.0f, 5.0f));

	bReplicates = true;
}

void APlaceActor::BeginPlay()
{
	Super::BeginPlay();

}

void APlaceActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(APlaceActor, FloorNumber);


}

void APlaceActor::SetFloorNumber(int32 Number)
{
	FloorNumber = Number;

}

int32 APlaceActor::GetFloorNumber()
{
	return FloorNumber;
}

void APlaceActor::SetFloorColor()
{

	if (FloorNumber == 1)
	{
		Floor->SetSprite(Floor1);
	}
	else if (FloorNumber == 2)
	{
		Floor->SetSprite(Floor2);
	}
	else if (FloorNumber == 3)
	{
		Floor->SetSprite(Floor3);
	}
	else if (FloorNumber == 4)
	{
		Floor->SetSprite(Floor4);
	}
}



void APlaceActor::OnRep_FloorNumber()
{
	SetFloorColor();
}

bool APlaceActor::ServerSetFloorNumber_Validate(int32 Number)
{
	return true;
}

void APlaceActor::ServerSetFloorNumber_Implementation(int32 Number)
{
	if (Role == ROLE_Authority)
	{
		FloorNumber = Number;
		OnRep_FloorNumber();
	}
}