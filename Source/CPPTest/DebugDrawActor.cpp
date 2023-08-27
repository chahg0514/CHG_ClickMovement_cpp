// Fill out your copyright notice in the Description page of Project Settings.


#include "DebugDrawActor.h"

#include "DrawDebugHelpers.h"

// Sets default values
ADebugDrawActor::ADebugDrawActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	//�� ������Ʈ ����

	InitLocation[0] = FVector::ZeroVector;
	//FVector::ZeroVector = (0,0,0)
	InitLocation[1] = FVector(0, 1000, 0);
	InitLocation[2] = FVector(0, 400, 0);
	InitLocation[3] = FVector(0, 1600, 0);
	InitLocation[4] = FVector(300, 1000, 0);

	Box = FBox(FVector(-50, -100, -50), FVector(50, 100, 50));
	Transform.SetLocation(FVector(200, 1600, 0));
}

// Called when the game starts or when spawned
void ADebugDrawActor::BeginPlay()
{
	Super::BeginPlay();

	for (int i = 0; i < 5; i++)
	{
		Location[i] = InitLocation[i] + GetActorLocation();
		//GetActorLocation() : ���� ������ ��ġ�� ��ȯ, ���� ������ ��ġ�� ���ؼ� ����
	}

	//����ü�� �׷���
	//(���� ����, ��ġ, ����, ��, ��������)
	DrawDebugBox(GetWorld(), Location[0] + Box.GetCenter(), Box.GetExtent(), FColor::Red, true);
	//��ĥ�� ����ü
	DrawDebugSolidBox(GetWorld(), Location[0] + Box.GetCenter(), Box.GetExtent(), FColor::Green, true);
	//�� (����, ��ġ, ������, ��, ��������)
	DrawDebugPoint(GetWorld(), Location[1], 100, FColor::Red, true);
	//���� (����,������,�������,��,��������)
	DrawDebugSphere(GetWorld(), Location[2], 100, 50, FColor::Red, true);
	//��
	DrawDebugSphere(GetWorld(), Location[3], 100, 50, FColor::Red, true);
	//�� (����,��ġ,������,��,��������,�����ð�,���̰�,�β�)
	DrawDebugLine(GetWorld(), Location[2], Location[3], FColor::Magenta, true, -1, 0, 2);
	
}

// Called every frame
void ADebugDrawActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector location = Location[1];
	location.X += 100;
	location.Z += 100;
	location.Y += sin(GetWorld()->GetTimeSeconds() * 3.f) * 300.f;

	DrawDebugPoint(GetWorld(), location, 100, FColor::Emerald);
	DrawDebugDirectionalArrow(GetWorld(), location, Location[3], 360, FColor::Yellow, false, -1, 0); //ȭ��ǥ


}

