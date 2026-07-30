// Fill out your copyright notice in the Description page of Project Settings.


#include "Combat/CombatComponent.h"



UCombatComponent::UCombatComponent()
{
	
	PrimaryComponentTick.bCanEverTick = true;

	
}

void UCombatComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                     FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	
}

void UCombatComponent::Initiate_CycleWeapon()
{
	GEngine->AddOnScreenDebugMessage(-1,5.f,FColor::Cyan,TEXT("CycleWeapon"),false);
}

void UCombatComponent::Initiate_FireWeapon_Pressed()
{
	GEngine->AddOnScreenDebugMessage(-1,5.f,FColor::Cyan,TEXT("FireWeapon_Pressed"),false);
}

void UCombatComponent::Initiate_FireWeapon_Released()
{
	GEngine->AddOnScreenDebugMessage(-1,5.f,FColor::Cyan,TEXT("FireWeapon_Released"),false);
}

void UCombatComponent::Initiate_ReloadWeapon()
{
	GEngine->AddOnScreenDebugMessage(-1,5.f,FColor::Cyan,TEXT("ReloadWeapon"),false);
}

void UCombatComponent::Initiate_Aim_Pressed()
{
	GEngine->AddOnScreenDebugMessage(-1,5.f,FColor::Cyan,TEXT("Aim_Pressed"),false);
}

void UCombatComponent::Initiate_Aim_Released()
{
	GEngine->AddOnScreenDebugMessage(-1,5.f,FColor::Cyan,TEXT("Aim_Released"),false);
}

