// Fill out your copyright notice in the Description page of Project Settings.


#include "MeshActor.h"

// Sets default values
AMeshActor::AMeshActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true; //ƽ�Լ� ����Ұ��� ������

	MyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyMesh")); //�̸��� MyMesh�� �⺻ ������Ʈ ���� ����
	//CreateDefaultSubobject : ������Ʈ�� �������� ����
	//UObject�� ��ӹ޴� Ŭ������ �޸������� ���� �ʴ´�.
	//������ �÷��ǿ��� �޸������� ���ֱ� ����.(�̰Ŵ� ������ �˷��ذ��ε�)
	RootComponent = MyMesh;
	//ActorŬ������ transform ������ ����.
	//RootComponent�� �־��� ������Ʈ�� transform������ ���

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cylinder.Shape_Cylinder'"));
	//ConstructorHelpers: �����ڿ����� ���� ����, ������ ������>?
	//FObjectFinder: ������ ��θ� ������ �� �ִ� ����ü..?
	//Text�ȿ� ������ ������ ��θ� ������ �ȴ�. (StaticMesh�� �������� ��)

	if (MeshAsset.Succeeded()) //��ο� ������ ���ٸ�
	{
		MyMesh->SetStaticMesh(MeshAsset.Object); //��������� �޽��� ���͸� �����ϴ� ��
	}
	//���ǻ���
	//�����ڿ� ������ �ִٸ� �𸮾� ���� ������.

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

