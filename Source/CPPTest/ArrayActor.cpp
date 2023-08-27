// Fill out your copyright notice in the Description page of Project Settings.


#include "ArrayActor.h"

// Sets default values
AArrayActor::AArrayActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AArrayActor::BeginPlay()
{
	Super::BeginPlay();
	
	//�迭 ���̰� �������̴�.


	IntArray = { 10,20,30,40,50 };
	IntArray.Add(1);
	IntArray.Add(2);
	IntArray.Add(3);

	IntArray.Insert(100, 4); //4��° �ε����� 1000���߰�

	IntArray.Remove(3); //�迭 �� 3�� �� ��� ����
	IntArray.RemoveAt(5);
	//for (int i = 0; i < IntArray.Num(); i++)
	//{
	//	FString message = FString::Printf(TEXT("IntArray[%d]:%d"), i, IntArray[i]); //��Ʈ�� ũ�⸦ �������൵��
	//	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, message);
	//}

	TArray<FString> StrArr;
	StrArr = { TEXT("D"),TEXT("C") ,TEXT("A") ,TEXT("B") };
	StrArr.Sort();

	//auto: �ڵ����� �ڷ����� ������

	//������� for��
	//�ݺ��� ������ StrArr�迭�� ���� item������ ��
	//�迭 ũ�⸸ŭ �ݺ�
	
	for (auto item : StrArr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::Printf(TEXT("%s"), *item)); //
	}
	//for (auto iter = StrArr.CreateIterator(); iter; ++iter)
	//{
	//	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, FString::Printf(TEXT("%s"), **iter));
	//}

	ArrMap.Add(TEXT("Attack"), 123);
	auto message = FString::Printf(TEXT("Attack:%d"), ArrMap[TEXT("Attack")]);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, message);

	FloatArray = { 1,2,3,4,5 };
	for (auto i = 0; i < FloatArray.Num(); i++)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Black, FString::Printf(TEXT("%f"), FloatArray[i]));
	}

	for (auto i : FloatArray)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Black, FString::Printf(TEXT("%f"), i));
	}

}

// Called every frame
void AArrayActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

