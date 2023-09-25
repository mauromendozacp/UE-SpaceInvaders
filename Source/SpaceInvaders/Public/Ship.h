// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Character.h"

#include "Components/InputComponent.h"

#include "InputMappingContext.h"
#include "InputConfigData.h"
#include "InputAction.h"
#include "InputActionValue.h"

#include "Ship.generated.h"

UCLASS()
class SPACEINVADERS_API AShip : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AShip();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input Player")
	UInputMappingContext* inputMapping = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input Player")
	UInputConfigData* inputActions = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "General Settings", meta = (AllowPrivateAccess = "true"))
	int score = 0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "General Settings", meta = (AllowPrivateAccess = "true"))
	float speedMultiplier = 1.f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

private:
	void Move(const FInputActionValue& value);

	void SetupInputMapping();
	void SetupInputActions(UInputComponent* playerInputComponent);
};
