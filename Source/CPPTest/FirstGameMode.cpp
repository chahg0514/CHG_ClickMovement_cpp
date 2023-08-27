// Fill out your copyright notice in the Description page of Project Settings.


#include "FirstGameMode.h"
#include "MeshActor.h"
#include "CubeActor.h"

void AFirstGameMode::BeginPlay()
{
	Super::BeginPlay();

	FTransform SpawnLocation; //Ʈ������ ������ �������
	GetWorld()->SpawnActor<AMeshActor>
		(AMeshActor::StaticClass(), SpawnLocation);
	//GetWorld(): ���� ���带 ��ȯ
	//SpawnActor: ���͸� ����
	//StaticClass(): Ŭ���� Ÿ���� ��ȯ..? ���� �ȵ�

	FTransform SpawnTransform;
	SpawnTransform.SetLocation(FVector(200, 0, 0));

	MyMeshActor = GetWorld()->SpawnActor<AMeshActor>(AMeshActor::StaticClass(), SpawnTransform);
	FTimerHandle Timer; //Ÿ�̸Ӹ� ������ �� �ִ� �ڵ�
	//�ڵ�: �ü���� ���ϴ� ���ҽ� �ּҸ� ������ ġȯ�� ��, ���ҽ� �ּҶ�� ���� ��
	
	GetWorldTimerManager().SetTimer(Timer, this, &AFirstGameMode::MyMeshActorDestroy, 10);
	//MyMeshActorDestroy�Լ��� 10�� �Ŀ� ȣ���Ѵٴ� �ǹ�

	SpawnLocation.SetLocation(FVector(400, 0, 0));
	MyMeshActor2 = GetWorld()->SpawnActor<ACubeActor>(ACubeActor::StaticClass(), SpawnLocation);
	MyMeshActor2->SetLifeSpan(5.f);
	//SetLifeSpan: �����ð� �� ���� ����

	SpawnLocation.SetLocation(FVector(600, 0, 0));
	MyMeshActor3 = GetWorld()->SpawnActor<AMeshActor>(AMeshActor::StaticClass(), SpawnLocation); 
	//�������� �̰ɷ� �ϸ� ���������Ӹ��ƴ϶� ƨ���. ������Ͽ��� �����Ѱɷ� �ؾ� �� ������..

	FTimerHandle Timer2;
	GetWorld()->GetTimerManager().SetTimer(Timer2, FTimerDelegate::CreateLambda([&]()
		{
			MyMeshActor3->Destroy();
		}), 15.f, false); //15�� �� �����Լ��� ȣ����. �����Լ��� �̿��Ͽ� �����ð� �� �Լ� ȣ��, true ������ �ݺ�, false�� �ѹ���
}

void AFirstGameMode::MyMeshActorDestroy()
{
	if (MyMeshActor != nullptr)
	{
		MyMeshActor->Destroy();
		//�������� �� ���شٰ� �ߴµ� 7�� 11��
	}
}
