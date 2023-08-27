// Fill out your copyright notice in the Description page of Project Settings.


#include "TestActor.h"

// Sets default values
ATestActor::ATestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATestActor::BeginPlay()
{
	Super::BeginPlay();

	//로그 출력
	UE_LOG(LogTemp, Log, TEXT("Log"));
	UE_LOG(LogTemp, Warning, TEXT("Warning"));
	UE_LOG(LogTemp, Error, TEXT("Error"));
	//UE_LOG(카테고리,출력수준,TEXT("문자열"))
	//출력수준 종류: Log(흰색?), Warning(노란색),Error(빨간색)

	//변수 로그 출력
	int32 a = 10;
	float b = 12.34f;
	FString c = TEXT("Unreal"); //스트링 값 넣을 때 TEXT 매크로를 써야한다
	UE_LOG(LogTemp, Error, TEXT("a: %d"), a);
	UE_LOG(LogTemp, Error, TEXT("a: %f"), b);
	UE_LOG(LogTemp, Error, TEXT("a: %s"), *c); //스트링은 출력할 때 역포인터를 넣어줘야함

	//스크린 로그 출력
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Hello Unreal"));
	//AddOnScreenDebugMessage(처음에는 그냥 -1넣어주면 된다고 함, 시간, 색상, TEXT("문자열"));

	//스크린 변수값 로그 출력
	FString message = FString::Printf(TEXT("a: %d"), a);
	//FString::Printf : %d 같은 출력타입을 문자열로 변환시켜줌
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, message);
	
}

// Called every frame
void ATestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

