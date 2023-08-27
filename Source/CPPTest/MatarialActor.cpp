// Fill out your copyright notice in the Description page of Project Settings.


#include "MatarialActor.h"

#include "Materials/MaterialInstanceConstant.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetSystemLibrary.h"
// Sets default values
AMatarialActor::AMatarialActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_NarrowCapsule.Shape_NarrowCapsule'"));
	if (MeshAsset.Succeeded())
	{
		Mesh->SetStaticMesh(MeshAsset.Object);
	}

}

// Called when the game starts or when spawned
void AMatarialActor::BeginPlay()
{
	Super::BeginPlay();
	auto Asset = StaticLoadObject(UMaterialInstanceConstant::StaticClass(), NULL, TEXT("MaterialInstanceConstant'/Game/Material/Test_Mat_Inst.Test_Mat_Inst'")); 
	//��Ƽ�����ν��Ͻ��� �������ڴٰ� �ϰ�, text�� ��Ƽ���� ��θ� ������ ��

	UMaterialInstanceConstant* MaterialInst;
	MaterialInst = Cast<UMaterialInstanceConstant>(Asset);
	//if (Asset->IsAsset()) //������ ���������� �����Դٸ� (�̰� �ȵȴٰ� ���췡)
	//{
	//	
	//	//������ ��ü�� ��Ƽ���� �ν��Ͻ� ������Ʈ�� ����ȯ (Asset�� UObject�� �Ǿ��ֱ� ������ ĳ��Ʈ ���ִ� ����)
	//	//��Ƽ���� �ν��Ͻ��� �츮�� ���� �� Test_MatInst�� ���� �ڷ����ΰ���, ���̳����� ����
	//}

	Material = UMaterialInstanceDynamic::Create(MaterialInst, this);
	Material->BlendMode = BLEND_Translucent;
	//��Ƽ���� �ν��Ͻ� �����Ͻ��� ������� ��Ƽ���� �ν��Ͻ� ���̳����� ����

	Mesh->SetMaterial(0, Material);

	UKismetSystemLibrary::K2_SetTimer(this, "ChangeColor", 1.f, true);
	//�����ð� ���� ChangeColor �Լ� ȣ��, ���ʵ��� ������, �ݺ�����(�̰� ���� �ִ� �װ��ε�)
}

// Called every frame
void AMatarialActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMatarialActor::ChangeColor()
{
	FLinearColor Color;
	Color.R = UKismetMathLibrary::RandomFloatInRange(0, 1);
	Color.G = UKismetMathLibrary::RandomFloatInRange(0, 1);
	Color.B = UKismetMathLibrary::RandomFloatInRange(0, 1);
	//Color.A = UKismetMathLibrary::RandomFloatInRange(0, 1);
	Color.A = 1;
	Color.R = 1.f;
	Material->SetVectorParameterValue("Color", Color);
	//GEngine->AddOnScreenDebugMessage(-1, 0.1f, FColor::Cyan, TEXT("Material!"));
	//Color��� �����Ķ������ �̸��� ���� ����� �� ����
}

