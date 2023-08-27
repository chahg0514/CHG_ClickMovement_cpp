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
	//머티리얼인스턴스를 가져오겠다고 하고, text에 머티리얼 경로를 넣으면 됨

	UMaterialInstanceConstant* MaterialInst;
	MaterialInst = Cast<UMaterialInstanceConstant>(Asset);
	//if (Asset->IsAsset()) //에셋을 성공적으로 가져왔다면 (이건 안된다고 지우래)
	//{
	//	
	//	//가져온 객체를 머티리얼 인스턴스 컨스턴트로 형변환 (Asset이 UObject로 되어있기 때문에 캐스트 해주는 거임)
	//	//머티리얼 인스턴스는 우리가 만든 그 Test_MatInst랑 같은 자료형인가봐, 다이나믹은 뭐지
	//}

	Material = UMaterialInstanceDynamic::Create(MaterialInst, this);
	Material->BlendMode = BLEND_Translucent;
	//머티리얼 인스턴스 컨스턴스를 기반으로 머티리얼 인스턴스 다이나믹을 생성

	Mesh->SetMaterial(0, Material);

	UKismetSystemLibrary::K2_SetTimer(this, "ChangeColor", 1.f, true);
	//일정시간 이후 ChangeColor 함수 호출, 몇초동안 쉴건지, 반복여부(이거 노드로 있는 그거인듯)
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
	//Color라는 벡터파라미터의 이름을 가진 노드의 값 변경
}

