// Fill out your copyright notice in the Description page of Project Settings.


#include "../public/ChooseNextWaypoint.h"
#include "AIController.h"
#include "PatrolRouteComponent.h"
#include "VR_FPS.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	//Get Patrol Route
	
	auto ControlledPawn = OwnerComp.GetAIOwner()->GetPawn();
	auto PatrolRouteComponent = ControlledPawn->FindComponentByClass<UPatrolRouteComponent>();
	if (!ensure(PatrolRouteComponent)) { return EBTNodeResult::Failed; }

	// Warn about empty patrol routes
	auto PatrolPoints = PatrolRouteComponent->GetPatrolPoints();
	if (PatrolPoints.Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("A guard is missing patrol points"));
		return EBTNodeResult::Failed;
	}

	//Set next Patrol Points
	auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	auto Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	BlackboardComp->SetValueAsObject(WaypointKey.SelectedKeyName, PatrolPoints[Index]);


	//Cycle Index
	auto NextIndex = (Index + 1) % PatrolPoints.Num();
	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, NextIndex);
	return EBTNodeResult::Succeeded;
}
