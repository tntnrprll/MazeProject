// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"

ABaseCharacter::ABaseCharacter()
{
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = true;
	bUseControllerRotationRoll = false;

	GetCapsuleComponent()->SetCapsuleHalfHeight(96.0f);
	GetCapsuleComponent()->SetCapsuleRadius(40.0f);

	GetCapsuleComponent()->SetCollisionProfileName(TEXT("BaseCharacter_Collision"));
	
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 1000.0f;
	CameraBoom->RelativeRotation = FRotator(0.0f, -90.0f, 0.0f);

	SideViewCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("SideViewCamera"));
	SideViewCameraComponent->SetupAttachment(CameraBoom);

	GetCharacterMovement()->SetIsReplicated(true);
	
	
	bReplicates = true;
}

void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();

	GetCharacterMovement()->SetMovementMode(MOVE_Flying);
}

void ABaseCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ABaseCharacter, IsFlying);

}

void ABaseCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);


	PlayerInputComponent->BindAxis("MoveForward", this, &ABaseCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ABaseCharacter::MoveRight);


}

void ABaseCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

}


void ABaseCharacter::MoveForward(float Value)
{
	if (Value != 0.0f)
	{
		ServerSetMovementMode();

		AddMovementInput(FVector(0.0f, 0.0f, 1.0f), Value);
		

		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("1"));
	}
	

}

void ABaseCharacter::MoveRight(float Value)
{
	if (Value != 0.0f)
	{
		ServerSetMovementMode();

		AddMovementInput(FVector(0.0f, 1.0f, 0.0f), Value);
	
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("2"));
	}
	
}

void ABaseCharacter::ServerSetMovementMode_Implementation()
{
	if (Role == ROLE_Authority)
	{
		IsFlying = true;
		OnRep_IsFlying();
	}
}

bool ABaseCharacter::ServerSetMovementMode_Validate()
{
	return true;
}

void ABaseCharacter::OnRep_IsFlying()
{
	GetCharacterMovement()->SetMovementMode(MOVE_Flying);
}









