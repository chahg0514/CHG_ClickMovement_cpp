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
	RootComponent = MyMesh; //루트컴포넌트가 마이메쉬로 바뀌어?

	//콜리전
	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionComp")); //복습
	CollisionComp->InitSphereRadius(5.0f);
	CollisionComp->SetCollisionProfileName("OverlapAllDynamic");
	CollisionComp->OnComponentBeginOverlap.AddDynamic(this, &AShotActor::OnOverlapBegin); //오류 Add 를 All이라 적음
	CollisionComp->SetupAttachment(MyMesh);

	//프로젝타일
	Projectile = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile"));
	Projectile->InitialSpeed = 2000.f;
	Projectile->MaxSpeed = 2000.f;
	Projectile->ProjectileGravityScale = 0.0f;
	Projectile->bRotationFollowsVelocity = true; //속도에 따른 회전
	Projectile->UpdatedComponent = MyMesh; //무브먼트 컴포넌트가 이동시키(도록?고?) 업데이트해야하는 컴포넌트
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
	SetActorTickEnabled(IsActive); //틱함수 활성화 여부
	SetActorEnableCollision(IsActive); //콜리전 활성화 여부
	SetActorHiddenInGame(!IsActive); //감출지 여부(액터를)
	bActive = IsActive;
	if (bActive)
	{
		GetWorldTimerManager().SetTimer(TimerHandle, this, &AShotActor::Deactivate, 5.f, false);
		//3초 후 Deactivate 함수 호출
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
	Projectile->Velocity = Direction * Projectile->InitialSpeed; //아 이거 곱하기구나
}

void AShotActor::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFormSweep, const FHitResult& SweepResult)
{
	if (OtherActor->ActorHasTag(FName(TEXT("Enemy"))))
	{
		OtherActor->Destroy(); //상대액터 제거
		SetActive(false); //프로젝타일 비활성화
	}
}

