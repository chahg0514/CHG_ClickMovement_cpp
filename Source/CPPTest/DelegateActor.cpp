// Fill out your copyright notice in the Description page of Project Settings.


#include "DelegateActor.h"

// Sets default values
ADelegateActor::ADelegateActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADelegateActor::BeginPlay()
{
	Super::BeginPlay();
	DeleSingle.BindUObject(this, &ADelegateActor::Single); //�ι�° ���ڴ� �ּҸ� ������ �� ���� ADelegateActor::���� �Լ��̸��� ������ �ȵǳ�
	DeleOneParam.BindUObject(this, &ADelegateActor::OneParam);
	//DeleSingle��������Ʈ�� Single�Լ� ����

	DeleMulti.AddUObject(this, &ADelegateActor::MultiA); 
	DeleMulti.AddUObject(this, &ADelegateActor::MultiB);//B�� �������� �־����ϱ� B�� ���� �����
	DeleMultiOneParam.AddUObject(this, &ADelegateActor::MultiOneParamA);
	DeleMultiOneParam.AddUObject(this, &ADelegateActor::MultiOneParamB);

	//�̺�Ʈ
	DeleEvent.AddLambda([this]() {GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, TEXT("DeleEvent")); });
	DeleEventOneParam.AddLambda([this](int32 num) 
		{

			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, FString::Printf(TEXT("Event: %d"),num));
		});
	DynamicDele.AddDynamic(this, &ADelegateActor::Single);
	DynamicDele.AddDynamic(this, &ADelegateActor::MultiA);
	DynamicDele.AddDynamic(this, &ADelegateActor::MultiB);

	if (DynamicDele.IsBound())
	{
		DynamicDele.Broadcast();
	}
	DynamicDele.Clear();
}

void ADelegateActor::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	//Super: �θ�Ŭ����
	if (DeleSingle.IsBound())
	{
		DeleSingle.Execute(); //��������Ʈ�� ����� �Լ� ȣ��
	}
	DeleSingle.Unbind(); //��������Ʈ�� �Լ� ���� ���� 

	if (DeleOneParam.IsBound())
	{
		DeleOneParam.Execute(777);
	}
	DeleOneParam.Unbind();

	if (DeleMulti.IsBound())
	{
		DeleMulti.Broadcast(); //����� �Լ��� ��� ȣ��
	}
	DeleMulti.Clear(); //����� �Լ��� ��� ����

	if (DeleMultiOneParam.IsBound())
	{
		DeleMultiOneParam.Broadcast(888);
	}
	DeleMultiOneParam.Clear();

	//�̺�Ʈ
	if (DeleEvent.IsBound())
	{
		DeleEvent.Broadcast(); //�̺�Ʈ ȣ��
	}
	DeleEvent.Clear();

	if (DeleEventOneParam.IsBound())
	{
		DeleEventOneParam.Broadcast(10); //�̺�Ʈ ȣ��
	}
	DeleEventOneParam.Clear();
}

// Called every frame
void ADelegateActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADelegateActor::Single()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("SingleDelegate!"));
}

void ADelegateActor::OneParam(int32 num)
{
	FString message = FString::Printf(TEXT("num: %d"), num);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, message);
}

void ADelegateActor::MultiA()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, TEXT("MultiA"));
}

void ADelegateActor::MultiB()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, TEXT("MultiB"));
}

void ADelegateActor::MultiOneParamA(int32 numA)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, TEXT("MultiOneParamA"));
}

void ADelegateActor::MultiOneParamB(int32 numB)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, TEXT("MultiOneParamB"));
}

