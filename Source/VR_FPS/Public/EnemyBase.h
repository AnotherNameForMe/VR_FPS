// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnemyBase.generated.h"




class USkeletalMeshComponent;
class USoundBase;
class UAnimMontage;


UCLASS()
class VR_FPS_API AEnemyBase : public ACharacter
{
	GENERATED_BODY()

		

public:
	// Sets default values for this character's properties
	AEnemyBase();

	/** Gun mesh */
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		USkeletalMeshComponent* FP_Gun;

	/** Gun muzzle's offset from the characters location */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		FVector GunOffset;

	/** Sound to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		USoundBase* FireSound;

	/** AnimMontage to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		UAnimMontage* FireAnimation;

	/* This is when calculating the trace to determine what the weapon has hit */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		float WeaponRange;

	/* This is multiplied by the direction vector when the weapon trace hits something to apply velocity to the component that is hit */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		float WeaponDamage;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	
};
