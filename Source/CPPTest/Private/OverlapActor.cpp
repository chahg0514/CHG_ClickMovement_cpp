// Fill out your copyright notice in the Description page of Project Settings.


#include "OverlapActor.h"

// Sets default values
AOverlapActor::AOverlapActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyMesh"));
	static auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Wedge_B.Shape_Wedge_B'"));
	if (MeshAsset.Succeeded())
	{
		MyMesh->SetStaticMesh(MeshAsset.Object);
	}
	RootComponent = MyMesh;
	MyMesh->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	//OverlapAllDynamic: ������Ʈ Ÿ���� Dynamic, ��� Ÿ�԰� ��ħ
	//��ħ���� �浹 �� Generate Overlap Events�� ture���߸� ��ħ���� �浹 ����
}

// Called when the game starts or when spawned
void AOverlapActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AOverlapActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	

}

void AOverlapActor::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	FString Message = FString::Printf(TEXT("OtherActor: %s"), *OtherActor->GetName());
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, Message);
}

void AOverlapActor::NotifyActorEndOverlap(AActor* OtherActor)
{
	Super::NotifyActorEndOverlap(OtherActor);

	FString Message = FString::Printf(TEXT("OtherActor: %s"), *OtherActor->GetName());
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, Message);
}

