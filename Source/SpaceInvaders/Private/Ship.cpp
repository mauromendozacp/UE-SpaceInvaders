#include "Ship.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

#pragma region CONSTRUCTORS
// Sets default values
AShip::AShip()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}
#pragma endregion

#pragma region UNREAL_CALLS
// Called when the game starts or when spawned
void AShip::BeginPlay()
{
	Super::BeginPlay();

    GetCharacterMovement()->MaxWalkSpeed = GetCharacterMovement()->MaxWalkSpeed * speedMultiplier;
}

// Called every frame
void AShip::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
#pragma endregion

#pragma region OVERRIDE_METHODS
// Called to bind functionality to input
void AShip::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    SetupInputMapping();
    SetupInputActions(PlayerInputComponent);
}
#pragma endregion

#pragma region PRIVATE_METHODS
void AShip::Move(const FInputActionValue& value)
{
    if ((Controller != nullptr))
    {
        const FVector2D moveValue = value.Get<FVector2D>();
        const FRotator movementRotation(0, Controller->GetControlRotation().Yaw, 0);

        if (moveValue.X != 0.f)
        {
            const FVector direction = movementRotation.RotateVector(FVector::RightVector);

            AddMovementInput(direction, moveValue.X);
        }
    }
}
void AShip::SetupInputMapping()
{
    // Get the player controller
    APlayerController* playerController = Cast<APlayerController>(Controller);

    // Get the local player subsystem
    UEnhancedInputLocalPlayerSubsystem* playerInputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(playerController->GetLocalPlayer());
    // Clear out existing mapping, and add our mapping
    playerInputSubsystem->ClearAllMappings();
    playerInputSubsystem->AddMappingContext(inputMapping, 0);
}

void AShip::SetupInputActions(UInputComponent* playerInputComponent)
{
    // Get the EnhancedInputComponent
    UEnhancedInputComponent* enhancedInput = Cast<UEnhancedInputComponent>(playerInputComponent);
    if (enhancedInput != nullptr)
    {
        // Bind the actions
        enhancedInput->BindAction(inputActions->inputMove, ETriggerEvent::Triggered, this, &AShip::Move);
    }
}
#pragma endregion
