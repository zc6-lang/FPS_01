// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ShooterCharacter.generated.h"

UCLASS()
class FPS_API AShooterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AShooterCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
private:
	//1st person view (arms)
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USkeletalMeshComponent> Mesh1P;
	
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<class USpringArmComponent> SpringArm;
	
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<class UCameraComponent> FirstPersonCamera;
	
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<class UCombatComponent> Combat;
	
	UPROPERTY(EditDefaultsOnly,Category="FPS|Input")
	TObjectPtr<class UInputAction> CycleWeaponAction;
	
	UPROPERTY(EditDefaultsOnly,Category="FPS|Input")
	TObjectPtr<class UInputAction> FireWeaponAction;
	
	UPROPERTY(EditDefaultsOnly,Category="FPS|Input")
	TObjectPtr<class UInputAction> ReloadWeaponAction;
	
	UPROPERTY(EditDefaultsOnly,Category="FPS|Input")
	TObjectPtr<class UInputAction> AimWeaponAction;
	
	void Input_CycleWeapon();
	void Input_ReloadWeapon();
	void Input_FireWeapon_Pressed();
	void Input_FireWeapon_Released();
	void Input_Aim_Pressed();
	void Input_Aim_Released();
	
};
