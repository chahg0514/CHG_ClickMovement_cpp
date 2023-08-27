// Fill out your copyright notice in the Description page of Project Settings.


#include "ShotActor.h"

#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
AShotActor::AShotActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyMesh"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));
	if (MeshAsset.Succeeded())
	{
		MyMesh->SetStaticMesh(MeshAsset.Object);
	}
	MyMesh->SetCollisionProfileName("OverlapAllDynamic");
	MyMesh->SetRelativeScale3D(FVector(0.3f));
	RootComponent = MyMesh; //��Ʈ������Ʈ�� ���̸޽��� �ٲ��?

	//�ݸ���
	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionComp")); //����
	CollisionComp->InitSphereRadius(5.0f);
	CollisionComp->SetCollisionProfileName("OverlapAllDynamic");
	CollisionComp->OnComponentBeginOverlap.AddDynamic(this, &AShotActor::OnOverlapBegin); //���� Add �� All�̶� ����
	CollisionComp->SetupAttachment(MyMesh);

	//������Ÿ��
	Projectile = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile"));
	Projectile->InitialSpeed = 2000.f;
	Projectile->MaxSpeed = 2000.f;
	Projectile->ProjectileGravityScale = 0.0f;
	Projectile->bRotationFollowsVelocity = true; //�ӵ��� ���� ȸ��
	Projectile->UpdatedComponent = MyMesh; //�����Ʈ ������Ʈ�� �̵���Ű(����?��?) ������Ʈ�ؾ��ϴ� ������Ʈ
}

// Called when the game starts or when spawned
void AShotActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AShotActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AShotActor::SetActive(bool IsActive)
{
	SetActorTickEnabled(IsActive); //ƽ�Լ� Ȱ��ȭ ����
	SetActorEnableCollision(IsActive); //�ݸ��� Ȱ��ȭ ����
	SetActorHiddenInGame(!IsActive); //������ ����(���͸�)
	bActive = IsActive;
	if (bActive)
	{
		GetWorldTimerManager().SetTimer(TimerHandle, this, &AShotActor::Deactivate, 5.f, false);
		//3�� �� Deactivate �Լ� ȣ��
	}
}

void AShotActor::Deactivate()
{
	SetActive(false);
}

bool AShotActor::isActive()
{
	return bActive;
}

void AShotActor::FireInDirection(const FVector& Direction)
{
	Projectile->Velocity = Direction * Projectile->InitialSpeed; //�� �̰� ���ϱⱸ��
}

void AShotActor::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFormSweep, const FHitResult& SweepResult)
{
	if (OtherActor->ActorHasTag(FName(TEXT("Enemy"))))
	{
		OtherActor->Destroy(); //������ ����
		SetActive(false); //������Ÿ�� ��Ȱ��ȭ
	}
}

