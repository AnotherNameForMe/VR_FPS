// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "ChooseNextWaypoint.generated.h"

/**
 * 
 */
UCLASS()
class VR_FPS_API UChooseNextWaypoint : public UBTTaskNode
{
	GENERATED_BODY()

		virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	
protected:
	UPROPERTY(EditAnywhere)
		struct FBlackboardKeySelector IndexKey;
	UPROPERTY(EditAnywhere)
		struct FBlackboardKeySelector WaypointKey;
};
