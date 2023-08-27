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
	DeleSingle.BindUObject(this, &ADelegateActor::Single); //두번째 인자는 주소를 넣으면 됨 저거 ADelegateActor::없이 함수이름만 넣으면 안되나
	DeleOneParam.BindUObject(this, &ADelegateActor::OneParam);
	//DeleSingle델리게이트에 Single함수 연결

	DeleMulti.AddUObject(this, &ADelegateActor::MultiA); 
	DeleMulti.AddUObject(this, &ADelegateActor::MultiB);//B를 마지막에 넣었으니까 B가 먼저 실행됨
	DeleMultiOneParam.AddUObject(this, &ADelegateActor::MultiOneParamA);
	DeleMultiOneParam.AddUObject(this, &ADelegateActor::MultiOneParamB);

	//이벤트
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
	//Super: 부모클래스
	if (DeleSingle.IsBound())
	{
		DeleSingle.Execute(); //델리게이트와 연결된 함수 호출
	}
	DeleSingle.Unbind(); //델리게이트와 함수 연결 해제 

	if (DeleOneParam.IsBound())
	{
		DeleOneParam.Execute(777);
	}
	DeleOneParam.Unbind();

	if (DeleMulti.IsBound())
	{
		DeleMulti.Broadcast(); //연결된 함수를 모두 호출
	}
	DeleMulti.Clear(); //연결된 함수를 모두 해제

	if (DeleMultiOneParam.IsBound())
	{
		DeleMultiOneParam.Broadcast(888);
	}
	DeleMultiOneParam.Clear();

	//이벤트
	if (DeleEvent.IsBound())
	{
		DeleEvent.Broadcast(); //이벤트 호출
	}
	DeleEvent.Clear();

	if (DeleEventOneParam.IsBound())
	{
		DeleEventOneParam.Broadcast(10); //이벤트 호출
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

