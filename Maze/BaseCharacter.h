// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "Components/CapsuleComponent.h"
#include "Net/UnrealNetwork.h"
#include "Engine/World.h"
#include "Paper2D/Classes/PaperSpriteComponent.h"
#include "Net/UnrealNetwork.h"
#include "Paper2D/Classes/PaperFlipbook.h"
#include "Paper2D/Classes/PaperSprite.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "Camera/CameraComponent.h"
#include "FloorActor.h"
#include "Components/BoxComponent.h"
#include "BaseCharacter.generated.h"

/**
 * 
 */
UCLASS()
class MAZE_API ABaseCharacter : public APaperCharacter
{
	GENERATED_BODY()
	
public:
	ABaseCharacter();
	virtual void BeginPlay() override;
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void Tick(float DeltaSeconds) override;

protected:
		/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* SideViewCameraComponent;



protected:
	UFUNCTION(BlueprintCallable)
	void MoveForward(float Value);
	UFUNCTION(BlueprintCallable)
	void MoveRight(float Value);

public:
	UFUNCTION(Server, Reliable, WithValidation)
		void ServerSetMovementMode();
	bool ServerSetMovementMode_Validate();
	void ServerSetMovementMode_Implementation();


	UPROPERTY(ReplicatedUsing=OnRep_IsFlying)
		bool IsFlying = false;
	UFUNCTION()
		void OnRep_IsFlying();


};
