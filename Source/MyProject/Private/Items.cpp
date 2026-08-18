
// Fill out your copyright notice in the Description page of Project Settings.


#include "Items.h"

//DEFINE_LOG_CATEGORY(LogSparta);

// Sets default values
AItems::AItems()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	//"/Game/Resources/Props/SM_Chair.SM_Chair"
	// /Game/Resources/Materials/M_Metal_Gold.M_Metal_Gold
	//static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Resources/Props/SM_Chair.SM_Chair"));
	//if (MeshAsset.Succeeded())
	//{
	//	StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	//}
	//static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/Resources/Materials/M_Metal_Gold.M_Metal_Gold"));
	//if (MaterialAsset.Succeeded())
	//{
	//	StaticMeshComp->SetMaterial(0, MaterialAsset.Object);
	//}
	//UE_LOG(LogTemp, Warning, TEXT("%s Constructor"), *GetName());
	PrimaryActorTick.bCanEverTick = true;
	RotaSpeed = 90.0f;
}
//void AItem::PostInitializeComponents()
//{
//	Super::PostInitializeComponents();
//	UE_LOG(LogTemp, Warning, TEXT("%s PostInitializeComponents"), *GetName());
//
//}

void AItems::BeginPlay()
{
	Super::BeginPlay();
	//ue_log(logtemp, warning, text("%s beginplay"), *getname());
	//setactorlocation(fvector(300.0f, 200.0f, 100.0f));
	//setactorrotation(frotator(0.0f, 90.0f, 0.0f));
	//setactorscale3d(fvector(2.0f));//= 2,2,2

	//fvector newloc(300.0f, 200.0f, 100.0f);
	//frotator newro(0.0f, 90.0f, 0.0f);
	//fvector newscale(2.0f);

	//ftransform newtr(newro, newloc, newscale);

	//setactortransform(newtr);
}

void AItems::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!FMath::IsNearlyZero(RotaSpeed))
	{
		AddActorLocalRotation(FRotator(0.0f, RotaSpeed * DeltaTime, 0.0f));
	}

	//UE_LOG(LogTemp, Warning, TEXT("%s Tick"), *GetName());

}

void AItems::ResetActorPosition()
{
	SetActorLocation(FVector::ZeroVector);
}
float AItems::GetRotationSpeed() const
{
	return RotaSpeed;
}
//void AItem::Destroyed()
//{
//	UE_LOG(LogTemp, Warning, TEXT("%s Destroyed"), *GetName());
//
//	Super::Destroyed();
//
//}
//void AItem::EndPlay(const EEndPlayReason::Type EndPlayReason)
//{
//	UE_LOG(LogTemp, Warning, TEXT("%s EndPlay"), *GetName());
//
//	Super::EndPlay(EndPlayReason);
//
//}

// 생성자 = 메모리에 생김. 딱 한번 호출.
// PostInitializeComponents() - 컴포넌트가 완성한 직후 호출, 컴포넌트끼리 데이터 주고받기, 상호작용
// BeginPaly() - 배치(spawn) 직후
// Tick(float DeltaTime) - 매 프레임마다 호출.
// Destroyed() - 삭제가 되기 직전에 호출된다.
// EndPlay() = 게임 종료, 파괴(Destroyed()), 레벨전환(씬전환)

// D -> E
// EndPlay
