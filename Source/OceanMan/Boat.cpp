#include "Boat.h"
#include "Components/InputComponent.h"
#include "WheeledVehicleMovementComponent.h"
#include "OceanController.h"
#include "Engine.h"

// Sets default values
ABoat::ABoat()
{
    // Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    // Don't rotate when the controller rotates. Let that just affect the camera.
    bUseControllerRotationPitch = false;
    bUseControllerRotationYaw = false;
    bUseControllerRotationRoll = false;
    boatMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
    RootComponent = boatMesh;
    boatMesh->SetEnableGravity(false);

    UWheeledVehicleMovementComponent *movementComponent = GetVehicleMovementComponent();

    // Wheels
    TArray<FWheelSetup> wheelSetups;


    // Create a camera boom (pulls in towards the player if there is a collision)
    cameraArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraArm"));
    cameraArm->SetupAttachment(RootComponent);
    cameraArm->TargetArmLength = 1200.0f;      // The camera follows at this distance behind the character
    cameraArm->bUsePawnControlRotation = true; // Rotate the arm based on the controller
    cameraArm->bInheritPitch = false;

    // Create a follow camera
    camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    camera->SetupAttachment(cameraArm, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
    camera->bUsePawnControlRotation = false;                              // Camera does not rotate relative to arm
}

// Called when the game starts or when spawned
void ABoat::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void ABoat::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}
