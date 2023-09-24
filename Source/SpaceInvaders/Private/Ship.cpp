#include "Ship.h"

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

	PlayerInputComponent->BindAxis(moveHorKey, this, &AShip::Move);
}
#pragma endregion

#pragma region PRIVATE_METHODS
void AShip::Move(float axisValue)
{
    if ((Controller != nullptr) && (axisValue != 0.0f))
    {
        const FRotator Rotation = Controller->GetControlRotation();
        const FRotator YawRotation(0, Rotation.Yaw, 0);

        const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

        AddMovementInput(Direction, axisValue);
    }
}
#pragma endregion
