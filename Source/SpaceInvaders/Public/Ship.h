// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Character.h"

#include "Ship.generated.h"

UCLASS()
class SPACEINVADERS_API AShip : public ACharacter
{
	GENERATED_BODY()

	const FName moveHorKey = "MoveHorizontal";

public:
	// Sets default values for this character's properties
	AShip();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "General Settins", meta = (AllowPrivateAccess = "true"))
	int score = 0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "General Settins", meta = (AllowPrivateAccess = "true"))
	float speedMultiplier = 1.f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	void Move(float axisValue);

};
