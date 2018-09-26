// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "HandControllerBase.h"
#include "VR_Character.generated.h"

UCLASS()
class VR_FPS_API AVR_Character : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AVR_Character();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadWrite)
		class USceneComponent* VRRoot;

private:

	void MoveForward(float Throttle);
	void MoveRight(float Throttle);

	void RightTriggerPressed() { if (RightHandController) RightHandController->TriggerPressed(); }
	void RightTriggerReleased() { if (RightHandController) RightHandController->TriggerReleased(); }


private:
	UPROPERTY(VisibleAnywhere)
		class UCameraComponent* Camera;



	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<AHandControllerBase> HandControllerClass;

	UPROPERTY()
		AHandControllerBase* RightHandController;



};




