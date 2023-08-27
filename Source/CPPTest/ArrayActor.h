// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ArrayActor.generated.h"

UCLASS()
class CPPTEST_API AArrayActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AArrayActor();
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY() //언리얼 배열 헤더파일에 선언 할 시 적어야함(메모리 관련 버그가 발생할 수 있음)
		TArray<int32> IntArray;
	UPROPERTY()//언리얼 맵 헤더파일에 선언 할 시 적어야함
		TMap<FString, int32> ArrMap;
	UPROPERTY()
		TArray<float> FloatArray;

};
