// Fill out your copyright notice in the Description page of Project Settings.


#include "Items2.h"



// Sets default values
AItems2::AItems2()
{
    PrimaryActorTick.bCanEverTick = true;

    SceneRoot =
        CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
    SetRootComponent(SceneRoot);

    StaticMeshComp =
        CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
    StaticMeshComp->SetupAttachment(SceneRoot);

}

void AItems2::BeginPlay()
{
    Super::BeginPlay();

    StartLocation = GetActorLocation();
}

void AItems2::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (MoveSpeed <= 0.0f || MaxRange <= 0.0f)
    {
        return;
    }

    CurrentDistance += MoveSpeed * DirectionSign * DeltaTime;

    if (CurrentDistance >= MaxRange)
    {
        CurrentDistance = MaxRange;
        DirectionSign = -1.0f;
    }
    else if (CurrentDistance <= -MaxRange)
    {
        CurrentDistance = -MaxRange;
        DirectionSign = 1.0f;
    }

    const FVector NewLocation =
        StartLocation +
        MoveDirection.GetSafeNormal() * CurrentDistance;

    SetActorLocation(NewLocation);
}