
// Fill out your copyright notice in the Description page of Project Settings.


#include "Bomb.h"

ABomb::ABomb()
{
	Collision = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision"));
	Collision->SetupAttachment(RootComponent);
	Collision->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	Collision->SetRelativeScale3D(FVector(1.0f, 1.0f, 1.0f));
	Collision->SetCollisionProfileName(TEXT("Bomb_Collision"));

	GetRenderComponent()->SetRelativeScale3D(FVector(3.0f, 3.0f, 3.0f));
	GetRenderComponent()->SetCollisionProfileName(TEXT("NoCollision"));
	

	SetReplicates(true);
}

void ABomb::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(CountdownTimerHandle, this, &ABomb::AdvanceTimer, 1.0f, true);

}

void ABomb::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ABomb, CountdownTime);


}

void ABomb::AdvanceTimer()
{
	--CountdownTime;
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Some variable values:  %d"), CountdownTime));

	if (CountdownTime < 1)
	{
		GetWorldTimerManager().ClearTimer(CountdownTimerHandle);
		CountdownHasFinished();
	}
}

void ABomb::CountdownHasFinished()
{
	TArray<AActor*> OverlapActors;

	GetOverlappingActors(OverlapActors);
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Overlap actor number  %d"), OverlapActors.Num()));

	for (AActor* Actor : OverlapActors)
	{
		AFloorActor* OverlapActor = Cast<AFloorActor>(Actor);
		if (FloorActor)
		{
			FVector Location = OverlapActor->GetActorLocation();
			OverlapActor->ServerSetIsActive();
			AttempToSpawnFloor(Location);
			
		}
		
	}
	Destroy();

	
}



void ABomb::SetCountdownTime(int32 Number)
{
	CountdownTime = Number;
}

bool ABomb::ServerSpawnFloor_Validate(FVector Location)
{
	return true;
}

void ABomb::ServerSpawnFloor_Implementation(FVector Location)
{
	SpawnFloor(Location);
}

void ABomb::SpawnFloor(FVector Location)
{
	FActorSpawnParameters SpawnParameters;
	GetWorld()->SpawnActor<AFloorActor>(FloorActor, Location, FRotator(0.0f, 0.0f, 0.0f), SpawnParameters);

	
}

void ABomb::AttempToSpawnFloor(FVector Location)
{
	if (Role < ROLE_Authority)
	{
		//ServerSpawnFloor(Location);
	}
	else
	{
		SpawnFloor(Location);
	}
}

