// Fill out your copyright notice in the Description page of Project Settings.


#include "BlockActor.h"

// Sets default values
ABlockActor::ABlockActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyMesh")); //O�� o �ٸ��� ��Ÿ...
	static auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'")); 
	//�̷������� auto �Ἥ ã������ ����
	if (MeshAsset.Succeeded())
	{
		MyMesh->SetStaticMesh(MeshAsset.Object);
	}
	RootComponent = MyMesh;
	MyMesh->SetNotifyRigidBodyCollision(true);
	//�ݸ����� SimulationGenerates Hit Events�� true��
	//������ ����� ���¸� SimulationGenerates Hit Events�� true�� �־��
	//NotifyHit�Լ��� ȣ���

}

// Called when the game starts or when spawned
void ABlockActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABlockActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABlockActor::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	Super::NotifyHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);
	//�ϴ� �θ� ����, ���ϸ� ���� �������� �� ����
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("BlockActor is Hit!!"));
}

