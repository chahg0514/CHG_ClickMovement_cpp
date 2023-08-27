// Fill out your copyright notice in the Description page of Project Settings.


#include "CollisionActor.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
ACollisionActor::ACollisionActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SphereCollision = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere")); //��
	SphereCollision->InitSphereRadius(100.f); //�浹������ 100���� ����
	SphereCollision->OnComponentBeginOverlap.AddDynamic(this, &ACollisionActor::OnOverlapBegin); //�Լ��� ��������� ����
	//��������Ʈ�� ����(������ ����)
	MyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyMesh"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));
	//auto Ű����� ���� ������� �ʴ� ���� ����.
	if (MeshAsset.Succeeded())
	{
		MyMesh->SetStaticMesh(MeshAsset.Object);
	}
	RootComponent = MyMesh;
	SphereCollision->SetupAttachment(MyMesh);

	static ConstructorHelpers::FObjectFinder<UParticleSystem> ParticleAsset(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Explosion.P_Explosion'"));
	if (ParticleAsset.Succeeded())
	{
		Particle = ParticleAsset.Object;
	}



}

// Called when the game starts or when spawned
void ACollisionActor::BeginPlay()
{
	Super::BeginPlay();
	//Log(ELogLevel::W)
}

// Called every frame
void ACollisionActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACollisionActor::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), Particle, GetActorLocation());
	//Ư�� ��ġ�� ��ƼŬ�� ����
	Destroy(); //���� ���� ����
}

