// Fill out your copyright notice in the Description page of Project Settings.


#include "MissileActor.h"
#include "EnemyCharacter.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
AMissileActor::AMissileActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyMesh"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Torus.Shape_Torus'"));
	if (MeshAsset.Succeeded())
	{
		MyMesh->SetStaticMesh(MeshAsset.Object);
	}

	MyMesh->SetCollisionProfileName("OverlapAllDynamic");
	MyMesh->SetRelativeScale3D(FVector(0.5f));
	RootComponent = MyMesh;
	//MyMesh->SetNotifyRigidBodyCollision(true);

	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionComp")); 
	CollisionComp->InitSphereRadius(5.0f);
	CollisionComp->SetCollisionProfileName("OverlapAllDynamic");
	CollisionComp->OnComponentBeginOverlap.AddDynamic(this, &AMissileActor::OnOverlapBegin); //오류 Add 를 All이라 적음
	CollisionComp->SetupAttachment(MyMesh);

	Projectile = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile"));
	Projectile->InitialSpeed = 2000.f;
	Projectile->MaxSpeed = 2000.f;
	Projectile->ProjectileGravityScale = 0.0f;
	Projectile->bRotationFollowsVelocity = true; 
	Projectile->UpdatedComponent = MyMesh;



}

// Called when the game starts or when spawned
void AMissileActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMissileActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void AMissileActor::SetActive(bool IsActive)
{
	SetActorTickEnabled(IsActive); 
	SetActorEnableCollision(IsActive); 
	SetActorHiddenInGame(!IsActive); 
	bActive = IsActive;
	if (bActive)
	{

		GetWorldTimerManager().SetTimer(TimerHandle, this, &AMissileActor::Deactivate, 5.f, false);
	}
}

void AMissileActor::Deactivate()
{
	SetActive(false);
}

bool AMissileActor::isActive()
{
	return bActive;
}

void AMissileActor::FireInDirection(const FVector& Direction)
{
	Projectile->Velocity = Direction * Projectile->InitialSpeed; 
}

void AMissileActor::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFormSweep, const FHitResult& SweepResult)
{
	if (OtherActor->ActorHasTag(FName(TEXT("Enemy"))))
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Enemy Overlap Destroy"));

		OtherActor->Destroy(); //상대액터 제거
		SetActive(false); //프로젝타일 비활성화
	}
}

void AMissileActor::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	if (OtherActor->IsA(AEnemyCharacter::StaticClass()))
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Enemy Overlap"));
		OtherActor->Destroy();
	}
	
}

void AMissileActor::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	if (Other->IsA(AEnemyCharacter::StaticClass()))
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Enemy Hit"));
		//Other->Destroy();
	}
}


