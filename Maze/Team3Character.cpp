// Fill out your copyright notice in the Description page of Project Settings.


#include "Team3Character.h"


ATeam3Character::ATeam3Character()
{
	GetCapsuleComponent()->SetCollisionProfileName(TEXT("Team3Character_Collision"));

	static ConstructorHelpers::FObjectFinder<UPaperFlipbook> PLAYER(TEXT("PaperFlipbook'/Game/Image/FlipBook/BasePlayerIdle3.BasePlayerIdle3'"));
	if (PLAYER.Succeeded())
	{
		GetSprite()->SetFlipbook(PLAYER.Object);
	}

	bReplicates = true;
}

void ATeam3Character::BeginPlay()
{
	Super::BeginPlay();

	
}


void ATeam3Character::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ATeam3Character, PlayerNumber);


}



int32 ATeam3Character::GetPlayerNumber()
{
	return PlayerNumber;
}