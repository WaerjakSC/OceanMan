#include "Boat.h"
#include "Components/InputComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "OceanController.h"

// Sets default values
ABoat::ABoat()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	boatMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BOAT"));
	RootComponent = boatMesh;
	// GetMesh()->SetEnableGravity(false);
	// GetMesh()->SetupAttachment(RootComponent);

	// UWheeledVehicleMovementComponent *movementComponent = GetVehicleMovementComponent();

	// Create a camera boom (pulls in towards the player if there is a collision)
	cameraArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraArm"));
	cameraArm->SetupAttachment(RootComponent);
	cameraArm->TargetArmLength = 1500.0f;	  // The camera follows at this distance behind the character
	cameraArm->bUsePawnControlRotation = true; // Rotate the arm based on the controller
	cameraArm->bInheritPitch = false;
	cameraArm->bInheritRoll = true;
	cameraArm->bInheritYaw = false;
	cameraArm->RelativeRotation = FRotator(-30.f, 90.f, 0.f);

	// Create a follow camera
	camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	camera->SetupAttachment(cameraArm, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	camera->bUsePawnControlRotation = false;							 // Camera does not rotate relative to arm
}

// Called when the game starts or when spawned
void ABoat::BeginPlay()
{
	Super::BeginPlay();
}