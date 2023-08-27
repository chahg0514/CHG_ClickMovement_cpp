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
	
	//배열 길이가 가변적이다.


	IntArray = { 10,20,30,40,50 };
	IntArray.Add(1);
	IntArray.Add(2);
	IntArray.Add(3);

	IntArray.Insert(100, 4); //4번째 인덱스에 1000값추가

	IntArray.Remove(3); //배열 내 3의 값 모두 제거
	IntArray.RemoveAt(5);
	//for (int i = 0; i < IntArray.Num(); i++)
	//{
	//	FString message = FString::Printf(TEXT("IntArray[%d]:%d"), i, IntArray[i]); //스트링 크기를 안정해줘도됨
	//	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, message);
	//}

	TArray<FString> StrArr;
	StrArr = { TEXT("D"),TEXT("C") ,TEXT("A") ,TEXT("B") };
	StrArr.Sort();

	//auto: 자동으로 자료형을 정해줌

	//범위기반 for문
	//반복할 때마다 StrArr배열의 값이 item변수에 들어감
	//배열 크기만큼 반복
	
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

