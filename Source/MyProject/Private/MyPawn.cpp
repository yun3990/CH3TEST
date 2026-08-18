// Fill out your copyright notice in the Description page of Project Settings.
#include "SpartaPlayerController.h"
#include "EnhancedInputComponent.h"
#include "InputActionValue.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "MyPawn.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
// Sets default values
AMyPawn::AMyPawn()
{
    PrimaryActorTick.bCanEverTick = true;

    CapsuleComp =
        CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));

    SkeletalMeshComp =
        CreateDefaultSubobject<USkeletalMeshComponent>(
            TEXT("SkeletalMesh"));
    SpringArmComp =
        CreateDefaultSubobject<USpringArmComponent>(
            TEXT("SpringArm"));
    CameraComp =
        CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));

    CameraComp->SetupAttachment(
        SpringArmComp,
        USpringArmComponent::SocketName
    );

    CameraComp->bUsePawnControlRotation = false;
    SpringArmComp->SetupAttachment(CapsuleComp);
    SpringArmComp->TargetArmLength = 300.0f;
    SpringArmComp->bUsePawnControlRotation = false;

    SkeletalMeshComp->SetupAttachment(CapsuleComp);
    SkeletalMeshComp->SetSimulatePhysics(false);
    SkeletalMeshComp->SetCollisionEnabled(
        ECollisionEnabled::NoCollision);
}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPawn::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    const FVector2D NormalizedInput =
        MoveInput.GetClampedToMaxSize(1.0f);

    const FVector LocalOffset(
        NormalizedInput.X * MoveSpeed * DeltaTime,
        NormalizedInput.Y * MoveSpeed * DeltaTime,
        0.0f
    );

    AddActorLocalOffset(LocalOffset, true);

    const float YawDelta =
        LookInput.X * LookSpeed * DeltaTime;

    const float PitchDelta =
       -LookInput.Y * LookSpeed * DeltaTime;

    // Pawn은 좌우로만 회전
    AddActorLocalRotation(
        FRotator(0.0f, YawDelta, 0.0f)
    );

    // Spring Arm은 위아래로 회전
    FRotator SpringArmRotation =
        SpringArmComp->GetRelativeRotation();

    SpringArmRotation.Pitch = FMath::Clamp(
        SpringArmRotation.Pitch + PitchDelta,
        -80.0f,
        80.0f
    );

    SpringArmRotation.Yaw = 0.0f;
    SpringArmRotation.Roll = 0.0f;

    SpringArmComp->SetRelativeRotation(SpringArmRotation);
}

void AMyPawn::Move(const FInputActionValue& Value)
{
    MoveInput = Value.Get<FVector2D>();
}

void AMyPawn::StopMove(const FInputActionValue& Value)
{
    MoveInput = FVector2D::ZeroVector;
}

void AMyPawn::Look(const FInputActionValue& Value)
{
    LookInput = Value.Get<FVector2D>();
}

void AMyPawn::StopLook(const FInputActionValue& Value)
{
    LookInput = FVector2D::ZeroVector;
}
void AMyPawn::SetupPlayerInputComponent(
    UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    UEnhancedInputComponent* EnhancedInput =
        Cast<UEnhancedInputComponent>(PlayerInputComponent);

    ASpartaPlayerController* PlayerController =
        Cast<ASpartaPlayerController>(GetController());

    if (!EnhancedInput || !PlayerController)
    {
        return;
    }

    if (PlayerController->MoveAction)
    {
        EnhancedInput->BindAction(
            PlayerController->MoveAction,
            ETriggerEvent::Triggered,
            this,
            &AMyPawn::Move
        );

        EnhancedInput->BindAction(
            PlayerController->MoveAction,
            ETriggerEvent::Completed,
            this,
            &AMyPawn::StopMove
        );
    }

    if (PlayerController->LookAction)
    {
        EnhancedInput->BindAction(
            PlayerController->LookAction,
            ETriggerEvent::Triggered,
            this,
            &AMyPawn::Look
        );

        EnhancedInput->BindAction(
            PlayerController->LookAction,
            ETriggerEvent::Completed,
            this,
            &AMyPawn::StopLook
        );
    }
}