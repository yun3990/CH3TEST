// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Items2.generated.h"

class USceneComponent;
class UStaticMeshComponent;

UCLASS()
class MYPROJECT_API AItems2 : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AItems2();

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    USceneComponent* SceneRoot;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UStaticMeshComponent* StaticMeshComp;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
    float MoveSpeed = 200.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
    float MaxRange = 500.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
    FVector MoveDirection = FVector(1.0f, 0.0f, 0.0f);

    FVector StartLocation;

    float CurrentDistance = 0.0f;
    float DirectionSign = 1.0f;

    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;
};
