// Fill out your copyright notice in the Description page of Project Settings.

#include "HandControllerBase.h"

#include "Components/StaticMeshComponent.h"

#include"GameFramework/Pawn.h"
#include"GameFramework/PlayerController.h"
#include "Haptics/HapticFeedbackEffect_Base.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"


// Sets default values
AHandControllerBase::AHandControllerBase()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MotionController = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("MotionController"));
	SetRootComponent(MotionController);
	
}

// Called when the game starts or when spawned
void AHandControllerBase::BeginPlay()
{
	Super::BeginPlay();

	OnActorBeginOverlap.AddDynamic(this, &AHandControllerBase::ActorBeginOverlap);
	OnActorEndOverlap.AddDynamic(this, &AHandControllerBase::ActorEndOverlap);

}

// Called every frame
void AHandControllerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void AHandControllerBase::ActorBeginOverlap(AActor * OverlappedActor, AActor * OtherActor)
{
	bool bNewCanGrab = CanGrab();
	if (!bCanGrab && bNewCanGrab)
	{
		APawn* Pawn = Cast<APawn>(GetAttachParentActor());
		if (Pawn != nullptr)
		{
			APlayerController* Controller = Cast<APlayerController>(Pawn->GetController());
			if (Controller != nullptr)
			{
				Controller->PlayHapticEffect(HapticEffect, EControllerHand::AnyHand);
			}
		}
	}
}
void AHandControllerBase::ActorEndOverlap(AActor * OverlappedActor, AActor * OtherActor)
{
	bCanGrab = CanGrab();
}
bool AHandControllerBase::CanGrab() const
{
	TArray<AActor*> OverlappingActors;
	GetOverlappingActors(OverlappingActors);
	for (AActor* OverlappingActor : OverlappingActors)
	{
		if (OverlappingActor->ActorHasTag(TEXT("Grabbable")))
		{
			return true;
		}
	}
	return false;
}
void AHandControllerBase::PairController(AHandControllerBase * Controller)
{
	OtherController = Controller;
	OtherController->OtherController = this;

}

void AHandControllerBase::Grip()
{
	if (!bCanGrab) return;
	if (!bIsGrabbed)
	{
		bIsGrabbed = true;
		APickUpBase* PickUpBase = Cast<APickUpBase>(GetAttachParentActor());
		GrabLoc = PickUpBase->GetActorLocation();
		OtherController->bIsGrabbed = false;

		
		if (PickUpBase != nullptr)
			{
			PickUpBase->PickUpObject->SetSimulatePhysics(false);
			PickUpBase->SetRootComponent(MotionController);
			}
	}
}

void AHandControllerBase::Release()
{
	if (bIsGrabbed)
	{
		bIsGrabbed = false;
		APickUpBase* PickUpBase = Cast<APickUpBase>(GetAttachParentActor());
		if (PickUpBase != nullptr)
		{
			PickUpBase->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
			PickUpBase->PickUpObject->SetSimulatePhysics(false);

		}
	}
}
