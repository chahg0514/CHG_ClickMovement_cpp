// Fill out your copyright notice in the Description page of Project Settings.


#include "FunctionActor.h"

// Sets default values
AFunctionActor::AFunctionActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFunctionActor::BeginPlay()
{
	Super::BeginPlay();
	DefineFromBlueprint();
	NativeTest();
	//C++에서는 주석 외에 한글 사용 불가
	GEngine->AddOnScreenDebugMessage(-1, 5.f,FColor::Black, TEXT("안녕"));
}

// Called every frame
void AFunctionActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

float AFunctionActor::BlueprintCall()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, TEXT("FuctionTest"));
	
	return 100.f;
}

int32 AFunctionActor::BlueprintPureA(int32 value)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, TEXT("BlueprintPureA"));
	return 50;
}

void AFunctionActor::GetVector(UPARAM(ref)FVector& value)
{
}

void AFunctionActor::NativeTest_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Red, TEXT("NativeTest"));
}

