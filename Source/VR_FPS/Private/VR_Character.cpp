// Fill out your copyright notice in the Description page of Project Settings.

#include "VR_Character.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/World.h"


// Sets default values
AVR_Character::AVR_Character()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	VRRoot = CreateDefaultSubobject<USceneComponent>(FName("VRRoot"));
	VRRoot->SetupAttachment(GetRootComponent());

	Camera = CreateDefaultSubobject<UCameraComponent>(FName("Camera"));
	Camera->SetupAttachment(VRRoot);



}

// Called when the game starts or when spawned
void AVR_Character::BeginPlay()
{
	Super::BeginPlay();

	LeftHandController = GetWorld()->SpawnActor<AHandControllerBase>(HandControllerClass);
	if (LeftHandController != nullptr)
	{
		LeftHandController->AttachToComponent(VRRoot, FAttachmentTransformRules::KeepRelativeTransform);
		LeftHandController->SetHand(EControllerHand::Left);
	}

	RightHandController = GetWorld()->SpawnActor<AHandControllerBase>(HandControllerClass);
	if (RightHandController != nullptr)
	{
		RightHandController->AttachToComponent(VRRoot, FAttachmentTransformRules::KeepRelativeTransform);
		RightHandController->SetHand(EControllerHand::Right);

	}

	LeftHandController->PairController(RightHandController);
}


// Called every frame
void AVR_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewCameraOffset = Camera->GetComponentLocation() - GetActorLocation();
	NewCameraOffset.Z = 0;
	AddActorWorldOffset(NewCameraOffset);
	VRRoot->AddWorldOffset(-NewCameraOffset);

}

// Called to bind functionality to input
void AVR_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("Forward"), this, &AVR_Character::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("Right"), this, &AVR_Character::MoveRight);
	PlayerInputComponent->BindAction(TEXT("GripLeft"), IE_Pressed, this, &AVR_Character::GripLeft);
	PlayerInputComponent->BindAction(TEXT("GripRight"), IE_Pressed, this, &AVR_Character::GripRight);
	PlayerInputComponent->BindAction(TEXT("ReleaseLeft"), IE_Released, this, &AVR_Character::ReleaseLeft);
	PlayerInputComponent->BindAction(TEXT("ReleaseRight"), IE_Released, this, &AVR_Character::ReleaseRight);
}

void AVR_Character::MoveForward(float Throttle)
{
	AddMovementInput(Throttle * Camera->GetForwardVector());
}

void AVR_Character::MoveRight(float Throttle)
{
	AddMovementInput(Throttle * Camera->GetRightVector());

}

