// Fill out your copyright notice in the Description page of Project Settings.

#include "CylinderActor.h"
#include "Components/TextRenderComponent.h"


// Sets default values
ACylinderActor::ACylinderActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//��Ʈ ���� �κ�
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;

	//�޽� ���� �κ�
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cylinder.Shape_Cylinder'"));
	if (MeshAsset.Succeeded())
	{
		Mesh->SetStaticMesh(MeshAsset.Object);
	}
	Mesh->SetRelativeScale3D(FVector(1, 1, 2.5f)); //ũ��

	//* �ؽ�Ʈ
	Text = CreateDefaultSubobject<UTextRenderComponent>(TEXT("Text"));
	Text->SetRelativeLocation(FVector(0, 0, 100));
	//SetRelativeLocation : ������ġ ����
	Text->SetRelativeRotation(FRotator(0, 180, 0));
	//���� ȸ���� ����
	Text->SetRelativeScale3D(FVector(2, 2, 0.8f));
	//ũ�� ����
	Text->HorizontalAlignment = EHorizTextAligment::EHTA_Center;
	//��� ����
	Text->Text = FText::FromString(GetName());
	//GetName(): ������ �̸��� ��ȯ
	//FText::FromString : FString Ÿ���� FText Ÿ������ ��ȯ

	//* ���� ����
	SetActorRotation(FRotator(0, -90.f, 0)); //ȸ���� ����
	Mesh->AttachTo(Root); //Mesh�� Root�� ����
	Text->AttachTo(Mesh); //Text�� Mesh�� ����

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

