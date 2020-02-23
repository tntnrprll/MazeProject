// Fill out your copyright notice in the Description page of Project Settings.


#include "Team4Character.h"


ATeam4Character::ATeam4Character()
{
	GetCapsuleComponent()->SetCollisionProfileName(TEXT("Team4Character_Collision"));

	static ConstructorHelpers::FObjectFinder<UPaperFlipbook> PLAYER(TEXT("PaperFlipbook'/Game/Image/FlipBook/BasePlayerIdle4.BasePlayerIdle4'"));
	if (PLAYER.Succeeded())
	{
		GetSprite()->SetFlipbook(PLAYER.Object);
	}

	bReplicates = true;
}

void ATeam4Character::BeginPlay()
{
	Super::BeginPlay();

}

void ATeam4Character::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ATeam4Character, PlayerNumber);


}



int32 ATeam4Character::GetPlayerNumber()
{
	return PlayerNumber;
}