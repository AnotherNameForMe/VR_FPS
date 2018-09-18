// Fill out your copyright notice in the Description page of Project Settings.

#include "A_VRCharacter.h"


// Sets default values
AA_VRCharacter::AA_VRCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AA_VRCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AA_VRCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AA_VRCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

