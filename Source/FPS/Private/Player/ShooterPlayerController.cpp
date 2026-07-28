// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/ShooterPlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Character.h"
AShooterPlayerController::AShooterPlayerController()
{
	bReplicates=true;
}

void AShooterPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	UEnhancedInputLocalPlayerSubsystem*Subsystem=ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (Subsystem)
	{
		Subsystem->AddMappingContext(ShooterIMC,0);
	}
}

void AShooterPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	UEnhancedInputComponent*ShooterInputComponent;
	ShooterInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
	ShooterInputComponent->BindAction(LookAction,ETriggerEvent::Triggered,this,&AShooterPlayerController::Input_Look);
	ShooterInputComponent->BindAction(MoveAction,ETriggerEvent::Triggered,this,&AShooterPlayerController::Input_Move);
	ShooterInputComponent->BindAction(JumpAction,ETriggerEvent::Started,this,&AShooterPlayerController::Input_Jump);
	ShooterInputComponent->BindAction(CrouchAction,ETriggerEvent::Started,this,&AShooterPlayerController::Input_Crouch);
}

void AShooterPlayerController::Input_Crouch()
{
	if (UCharacterMovementComponent*CMC=GetCharacter()->GetCharacterMovement())
	{
		CMC->bWantsToCrouch=!CMC->bWantsToCrouch;
	}
}

void AShooterPlayerController::Input_Jump()
{
	if (UCharacterMovementComponent*CMC=GetCharacter()->GetCharacterMovement())
	{
		if (CMC->bWantsToCrouch)
		{
			CMC->bWantsToCrouch=false;
		}else
		{
			GetCharacter()->Jump();
		}
	}
}

void AShooterPlayerController::Input_Move(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector=InputActionValue.Get<FVector2D>();
	const FRotator Rotation=GetControlRotation();
	const FRotator YawRotation(0.f,Rotation.Yaw,0.f);
	const FVector ForwardDirection=FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirectino=FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	GetPawn()->AddMovementInput(ForwardDirection,InputAxisVector.Y);
	GetPawn()->AddMovementInput(RightDirectino,InputAxisVector.X);
		
}

void AShooterPlayerController::Input_Look(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector=InputActionValue.Get<FVector2D>();
	AddYawInput(InputAxisVector.X);
	AddPitchInput(InputAxisVector.Y);
}
