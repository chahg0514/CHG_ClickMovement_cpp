// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DelegateActor.generated.h"

// 델리게이트
// 언리얼의 함수포인터
// 함수를 바인딩(연결)하고 원하는 시점에 호출할 수 있다.
//
//DECLARE_DELEGATE : 함수 1개를 바인딩할 수 있는 델리게이트

DECLARE_DELEGATE(FDeleSingle); //FDele이 델리게이트 이름, 델리게이트 정의
//DECLARE_DELEGATE_OneParam,TwoParam,ThreeParam 늘릴 수 있음
//DECLARE_DELEGATE(FDeleOneParamm, int32); //_OneParam이거 없이도 되네????
DECLARE_DELEGATE_OneParam(FDeleOneParam, int32);
DECLARE_DELEGATE_TwoParams(FDeleTwoParam, int32, int32);


//멀티캐스트 델리게이트
//함수포인터의 모음
//함수 여러개를 바인딩해서 한꺼번에 호출할 수 있다.

DECLARE_MULTICAST_DELEGATE(FDeleMulti); //이건 매개변수 못넣고
DECLARE_MULTICAST_DELEGATE_OneParam(FDeleMultiOneParam, int32);
DECLARE_MULTICAST_DELEGATE_TwoParams(FDeleMultiTwoParam, int32, int32);

//다이나믹 멀티캐스트 델리게이트
//블루프린트에서도 사용가능한 델리게이트(나머지는 C++에서만 사용 가능)
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

	FDeleSingle DeleSingle; //델리게이트 변수 선언


	UFUNCTION() //언리얼과 연결시켜줘야함
		void Single();
public:
	//델리게이트
	FDeleOneParam DeleOneParam;

	UFUNCTION()
		void OneParam(int32 num);
public:
	//멀티캐스트 델리게이트
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
	//이벤트
	//멀티캐스트 델리게이트와 유사하지만 전역(클래스 바깥)에서 정의할 수 없는 델리게이트
	//함수 여러개 연결 가능, 매개변수가 없는 함수 연결 가능, 있는것도 가능

	DECLARE_EVENT(ADelegateActor, FDeleEvent);
	DECLARE_EVENT_OneParam(ADelegateActor, FDeleEventOneParam, int32);

	FDeleEvent DeleEvent;
	FDeleEventOneParam DeleEventOneParam;
public:
	//다이나믹 멀티캐스트 델리게이트

	UPROPERTY(BlueprintAssignable,VisibleAnywhere,BlueprintCallable,Category = "Event")
		FDynamicDele DynamicDele;
	//BlueprintAssignable : 다이나믹델리게이트에만 사용할 수 있으며, 블루프린트에 노출시킴
	
};