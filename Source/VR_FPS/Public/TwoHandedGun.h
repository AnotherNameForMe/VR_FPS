// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PickUpBase.h"
#include "TwoHandedGun.generated.h"

/**
 * 
 */
UCLASS()
class VR_FPS_API ATwoHandedGun : public APickUpBase
{
	GENERATED_BODY()

public:
	int32 fi;
		void Fire();


	
};
