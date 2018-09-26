// Fill out your copyright notice in the Description page of Project Settings.

#include "VRHandController.h"

#include "Components/StaticMeshComponent.h"
#include "Engine/World.h"

#include "Engine/World.h"


// Sets default values
AVRHandController::AVRHandController()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	FlashLight = CreateDefaultSubobject<UStaticMeshComponent>(FName("FlashLight"));
	FlashLight->SetupAttachment(GetRootComponent());

}


void AVRHandController::BeginPlay()
{
	Super::BeginPlay();



}

// Called every frame
void AVRHandController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}
void AVRHandController::TriggerReleased()
{
}
void AVRHandController::TriggerPressed()
{
}