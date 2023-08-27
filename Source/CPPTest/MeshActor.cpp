// Fill out your copyright notice in the Description page of Project Settings.


#include "MeshActor.h"

// Sets default values
AMeshActor::AMeshActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true; //틱함수 사용할건지 말건지

	MyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyMesh")); //이름은 MyMesh롤 기본 오브젝트 만들어서 저장
	//CreateDefaultSubobject : 컴포넌트를 동적으로 생성
	//UObject를 상속받는 클래스는 메모리해제를 하지 않는다.
	//가비지 컬렉션에서 메모리해제를 해주기 때문.(이거는 전에도 알려준거인듯)
	RootComponent = MyMesh;
	//Actor클래스는 transform 정보가 없다.
	//RootComponent에 넣어준 컴포넌트의 transform정보를 사용

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cylinder.Shape_Cylinder'"));
	//ConstructorHelpers: 생성자에서만 생성 가능, 생성자 도움역할>?
	//FObjectFinder: 에셋의 경로를 가져올 수 있는 구조체..?
	//Text안에 가져올 에셋의 경로를 넣으면 된다. (StaticMesh를 가져오면 됨)

	if (MeshAsset.Succeeded()) //경로에 문제가 없다면
	{
		MyMesh->SetStaticMesh(MeshAsset.Object); //여기까지가 메쉬의 액터를 지정하는 것
	}
	//주의사항
	//생성자에 문제가 있다면 언리얼도 같이 터진다.

}

// Called when the game starts or when spawned
void AMeshActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMeshActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

