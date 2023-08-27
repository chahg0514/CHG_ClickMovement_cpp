// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DelegateActor.generated.h"

// ��������Ʈ
// �𸮾��� �Լ�������
// �Լ��� ���ε�(����)�ϰ� ���ϴ� ������ ȣ���� �� �ִ�.
//
//DECLARE_DELEGATE : �Լ� 1���� ���ε��� �� �ִ� ��������Ʈ

DECLARE_DELEGATE(FDeleSingle); //FDele�� ��������Ʈ �̸�, ��������Ʈ ����
//DECLARE_DELEGATE_OneParam,TwoParam,ThreeParam �ø� �� ����
//DECLARE_DELEGATE(FDeleOneParamm, int32); //_OneParam�̰� ���̵� �ǳ�????
DECLARE_DELEGATE_OneParam(FDeleOneParam, int32);
DECLARE_DELEGATE_TwoParams(FDeleTwoParam, int32, int32);


//��Ƽĳ��Ʈ ��������Ʈ
//�Լ��������� ����
//�Լ� �������� ���ε��ؼ� �Ѳ����� ȣ���� �� �ִ�.

DECLARE_MULTICAST_DELEGATE(FDeleMulti); //�̰� �Ű����� ���ְ�
DECLARE_MULTICAST_DELEGATE_OneParam(FDeleMultiOneParam, int32);
DECLARE_MULTICAST_DELEGATE_TwoParams(FDeleMultiTwoParam, int32, int32);

//���̳��� ��Ƽĳ��Ʈ ��������Ʈ
//�������Ʈ������ ��밡���� ��������Ʈ(�������� C++������ ��� ����)
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDynamicDele);


UCLASS()
class CPPTEST_API ADelegateActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADelegateActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FDeleSingle DeleSingle; //��������Ʈ ���� ����


	UFUNCTION() //�𸮾�� ������������
		void Single();
public:
	//��������Ʈ
	FDeleOneParam DeleOneParam;

	UFUNCTION()
		void OneParam(int32 num);
public:
	//��Ƽĳ��Ʈ ��������Ʈ
	FDeleMulti DeleMulti;
	FDeleMultiOneParam DeleMultiOneParam;

	UFUNCTION()
		void MultiA();
	UFUNCTION()
		void MultiB();
	UFUNCTION()
		void MultiOneParamA(int32 numA);
	UFUNCTION()
		void MultiOneParamB(int32 numB);
public:
	//�̺�Ʈ
	//��Ƽĳ��Ʈ ��������Ʈ�� ���������� ����(Ŭ���� �ٱ�)���� ������ �� ���� ��������Ʈ
	//�Լ� ������ ���� ����, �Ű������� ���� �Լ� ���� ����, �ִ°͵� ����

	DECLARE_EVENT(ADelegateActor, FDeleEvent);
	DECLARE_EVENT_OneParam(ADelegateActor, FDeleEventOneParam, int32);

	FDeleEvent DeleEvent;
	FDeleEventOneParam DeleEventOneParam;
public:
	//���̳��� ��Ƽĳ��Ʈ ��������Ʈ

	UPROPERTY(BlueprintAssignable,VisibleAnywhere,BlueprintCallable,Category = "Event")
		FDynamicDele DynamicDele;
	//BlueprintAssignable : ���̳��͵�������Ʈ���� ����� �� ������, �������Ʈ�� �����Ŵ
	
};