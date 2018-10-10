// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MotionControllerComponent.h"
#include "PickUpBase.h"
#include "Components/SceneComponent.h"

#include "HandControllerBase.generated.h"

UCLASS()
class VR_FPS_API AHandControllerBase : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AHandControllerBase();

	void SetHand(EControllerHand Hand) { MotionController->SetTrackingSource(Hand); }
	void PairController(AHandControllerBase* Controller);
	void Grip();
	void Release();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	

	
private:

	// Components
	UPROPERTY(VisibleAnywhere)
		UMotionControllerComponent* MotionController;

	AHandControllerBase* OtherController;

	UFUNCTION()
		void ActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor);
	UFUNCTION()
		void ActorEndOverlap(AActor* OverlappedActor, AActor* OtherActor);
	UPROPERTY(EditDefaultsOnly)
		class UHapticFeedbackEffect_Base* HapticEffect;

	bool CanGrab() const;
	bool bCanGrab = false;
	bool bIsGrabbed = false;

	FVector GrabLoc;
};
