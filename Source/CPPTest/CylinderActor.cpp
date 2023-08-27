// Fill out your copyright notice in the Description page of Project Settings.

#include "CylinderActor.h"
#include "Components/TextRenderComponent.h"


// Sets default values
ACylinderActor::ACylinderActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//루트 설정 부분
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;

	//메쉬 설정 부분
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cylinder.Shape_Cylinder'"));
	if (MeshAsset.Succeeded())
	{
		Mesh->SetStaticMesh(MeshAsset.Object);
	}
	Mesh->SetRelativeScale3D(FVector(1, 1, 2.5f)); //크기

	//* 텍스트
	Text = CreateDefaultSubobject<UTextRenderComponent>(TEXT("Text"));
	Text->SetRelativeLocation(FVector(0, 0, 100));
	//SetRelativeLocation : 로컬위치 변경
	Text->SetRelativeRotation(FRotator(0, 180, 0));
	//로컬 회전값 변경
	Text->SetRelativeScale3D(FVector(2, 2, 0.8f));
	//크기 변경
	Text->HorizontalAlignment = EHorizTextAligment::EHTA_Center;
	//가운데 정렬
	Text->Text = FText::FromString(GetName());
	//GetName(): 액터의 이름을 반환
	//FText::FromString : FString 타입을 FText 타입으로 변환

	//* 액터 설정
	SetActorRotation(FRotator(0, -90.f, 0)); //회전값 변경
	Mesh->AttachTo(Root); //Mesh를 Root에 부착
	Text->AttachTo(Mesh); //Text를 Mesh에 부착

}

// Called when the game starts or when spawned
void ACylinderActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACylinderActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

