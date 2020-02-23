// Fill out your copyright notice in the Description page of Project Settings.


#include "Team1Character.h"

ATeam1Character::ATeam1Character()
{
	GetCapsuleComponent()->SetCollisionProfileName(TEXT("Team1Character_Collision"));

	static ConstructorHelpers::FObjectFinder<UPaperFlipbook> PLAYER(TEXT("PaperFlipbook'/Game/Image/FlipBook/BasePlayerIdle1.BasePlayerIdle1'"));
	if (PLAYER.Succeeded())
	{
		GetSprite()->SetFlipbook(PLAYER.Object);
	}

	bReplicates = true;
}

void ATeam1Character::BeginPlay()
{
	Super::BeginPlay();

}


void ATeam1Character::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ATeam1Character, PlayerNumber);


}



int32 ATeam1Character::GetPlayerNumber()
{
	return PlayerNumber;
}