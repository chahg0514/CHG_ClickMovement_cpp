// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PublicActor.generated.h"

UCLASS()
class CPPTEST_API APublicActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APublicActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
// * �����������
// �𸮾��� ��⿡���� 3���� ������ �����ȴ�.
// Public: �ܺ� ��⿡ ������ ����
// Private: ���� ��⿡ ����� ����
// Classes: �𸮾� ������Ʈ ���� ��� ����

// ����� Public, �ҽ������� Private������ ����
// cpp������ ����Լ� ���ǿ뵵�̹Ƿ�
// �ܺο��� include���� �����Ƿ� private������ �־�д�.

// * ��� �߰� ��Ģ
// ����̸��� ������ ������ �ʿ��ϴ�.
// ����� ���� ��Ģ����: ����̸�.Build.cs
// ���� ���, �ҽ�����: ����̸�.h, ����̸�.cpp �̷��� �� 4������ �ʿ��� ���̴�(���� + 3����)
// Widgets��� �̸����� ��� ����� �غ�
