// Fill out your copyright notice in the Description page of Project Settings.


#include "FloorActor.h"

AFloorActor::AFloorActor()
{
	Collision = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision"));
	Collision->SetupAttachment(RootComponent);
	Collision->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	Collision->SetRelativeScale3D(FVector(3.0f, 3.0f, 3.0f));

	Floor = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("Floor"));
	Floor->SetupAttachment(Collision);
	Floor->SetRelativeRotation(FRotator(0.0f, 90.0f, 0.0f));
	Floor->SetCollisionProfileName(TEXT("NoCollision"));

	

	bReplicates = true;
}

void AFloorActor::BeginPlay()
{
	Super::BeginPlay();

}

void AFloorActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AFloorActor, FloorNumber);


}