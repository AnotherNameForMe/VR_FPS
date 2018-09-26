// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HandControllerBase.h"
#include "VRHandController.generated.h"

/**
 *
 */
UCLASS()
class VR_FPS_API AVRHandController : public AHandControllerBase
{
	GENERATED_BODY()

public:
	AVRHandController();

	void TriggerPressed() override;
	void TriggerReleased() override;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	UPROPERTY(EditDefaultsOnly)
		class UStaticMeshComponent* FlashLight;
};
