
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Items.generated.h"// 항상 마지막에 있어야함

//DECLARE_LOG_CATEGORY_EXTERN(LogSparta, Warning, All);

UCLASS()
class MYPROJECT_API AItems : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AItems();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Item|Components")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Components")
	UStaticMeshComponent* StaticMeshComp;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Item|Propertise")
	float RotaSpeed;
	//virtual void PostInitializeComponents() override;
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime)override;

	UFUNCTION(BlueprintCallable, Category = "Item|Action")
	void ResetActorPosition();

	UFUNCTION(BlueprintPure, Category = "Item|Propertise")
	float GetRotationSpeed() const;

	UFUNCTION(BlueprintImplementableEvent, Category = "Item|Event")
	void OnItemPickedUp();


	//virtual void Destroyed()override;
	//virtual void EndPlay(const EEndPlayReason::Type EndPlayReason)override;



};


// 생성자 = 메모리에 생김. 딱 한번 호출.
// PostInitializeComponents() - 컴포넌트가 완성한 직후 호출, 컴포넌트끼리 데이터 주고받기, 상호작용
// BeginPaly() - 배치(spawn) 직후
// Tick(float DeltaTime) - 매 프레임마다 호출.
// Destroyed() - 삭제가 되기 직전에 호출된다.
// EndPlay() = 게임 종료, 파괴(Destroyed()), 레벨전환(씬전환)

// D -> E
// EndPlay

