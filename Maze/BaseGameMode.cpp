// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseGameMode.h"

ABaseGameMode::ABaseGameMode()
{

	
	static ConstructorHelpers::FClassFinder<ABaseCharacter> CHARACTER(TEXT("Blueprint'/Game/Blueprint/BP_BaseCharacter1.BP_BaseCharacter1_C'"));
	if (CHARACTER.Succeeded())
	{
		DefaultPawnClass = CHARACTER.Class;
	}
	
	static ConstructorHelpers::FClassFinder<ABasePlayerController> PLAYERCONTROLLER(TEXT("Class'/Script/Maze.BasePlayerController'"));
	if (PLAYERCONTROLLER.Succeeded())
	{
		PlayerControllerClass = PLAYERCONTROLLER.Class;
	}

	bReplicates = true;
}

void ABaseGameMode::BeginPlay()
{
	Super::BeginPlay();


}

void ABaseGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);
	
	if (NewPlayer)
	{
			
		if (PlayerNumber == 1)
		{

			FActorSpawnParameters SpawnParameter;
			ATeam1Character* Player = GetWorld()->SpawnActor<ATeam1Character>(Player1, NewPlayer->GetPawn()->GetActorLocation() + FVector(300.0f, 0.0f, 0.0f), NewPlayer->GetPawn()->GetActorRotation(), SpawnParameter);
			Player->ServerSetMovementMode();
			Player->GetCharacterMovement()->GravityScale = 0.0f;

			NewPlayer->Possess(Player);
			

			PlayerNumber++;
		}
		else if (PlayerNumber == 2)
		{

			FActorSpawnParameters SpawnParameter;
			ATeam2Character* Player = GetWorld()->SpawnActor<ATeam2Character>(Player2, NewPlayer->GetPawn()->GetActorLocation() + FVector(300.0f, 0.0f, 0.0f), NewPlayer->GetPawn()->GetActorRotation(), SpawnParameter);
			Player->ServerSetMovementMode();
			Player->GetCharacterMovement()->GravityScale = 0.0f;

			NewPlayer->Possess(Player);

			PlayerNumber++;
		}
		else if (PlayerNumber == 3)
		{

			FActorSpawnParameters SpawnParameter;
			ATeam3Character* Player = GetWorld()->SpawnActor<ATeam3Character>(Player3, NewPlayer->GetPawn()->GetActorLocation() + FVector(300.0f, 0.0f, 0.0f), NewPlayer->GetPawn()->GetActorRotation(), SpawnParameter);
			Player->ServerSetMovementMode();
			Player->GetCharacterMovement()->GravityScale = 0.0f;

			NewPlayer->Possess(Player);

			PlayerNumber++;
		}
		else if (PlayerNumber == 4)
		{

			FActorSpawnParameters SpawnParameter;
			ATeam4Character* Player = GetWorld()->SpawnActor<ATeam4Character>(Player4, NewPlayer->GetPawn()->GetActorLocation() + FVector(300.0f, 0.0f, 0.0f), NewPlayer->GetPawn()->GetActorRotation(), SpawnParameter);
			Player->ServerSetMovementMode();
			Player->GetCharacterMovement()->GravityScale = 0.0f;

			NewPlayer->Possess(Player);
		}
		
		
	}
	

}
