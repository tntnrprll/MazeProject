// Fill out your copyright notice in the Description page of Project Settings.


#include "Team2Character.h"


ATeam2Character::ATeam2Character()
{
	GetCapsuleComponent()->SetCollisionProfileName(TEXT("Team2Character_Collision"));

	static ConstructorHelpers::FObjectFinder<UPaperFlipbook> PLAYER(TEXT("PaperFlipbook'/Game/Image/FlipBook/BasePlayerIdle2.BasePlayerIdle2'"));
	if (PLAYER.Succeeded())
	{
		GetSprite()->SetFlipbook(PLAYER.Object);
	}

	bReplicates = true;
}

void ATeam2Character::BeginPlay()
{
	Super::BeginPlay();

}


void ATeam2Character::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ATeam2Character, PlayerNumber);


}



int32 ATeam2Character::GetPlayerNumber()
{
	return PlayerNumber;
}