// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FunctionActor.generated.h"

UCLASS()
class CPPTEST_API AFunctionActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFunctionActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//UFUCTION()
	//함수를 언리얼에 등록시키는 매크로
	//함수를 언리얼과 관련된 기능과 연동하기 위해서 적어야 함
	// BlueprintCallable: 함수를 블루프린트에서 사용 가능하게 해줌
	// BlueprintPure : 함수를 퓨어함수로 블루프린트에서 사용 가능
	//

	UFUNCTION(BlueprintCallable, Category = "Test")
	float BlueprintCall();

	UFUNCTION(BlueprintPure, Category = "Test")
	int32 BlueprintPureA(int32 value);

	//BlueprintImplementableEvent : 정의는 블루프린트에서 만듦
	UFUNCTION(BlueprintImplementableEvent, Category = "Test")
	void DefineFromBlueprint();

	//BlueprintNativeEvent
	//C++에서도 정의 가능하며 블루프린트에서 오버라이드 하여 사용
	//C++에서 정의가 있으므로 블루프린트에서 정의하지 않아도 됨
	//C++에서 정의할때는 이름에 "_Implementtion을 적어야 한다.
	//호출은 여기서 해야됨
	UFUNCTION(BlueprintNativeEvent, Category = "Test")
		void NativeTest();

	UFUNCTION(BlueprintPure, Category = "Test")
		void GetVector(UPARAM(ref) FVector& value);
	//함수를 블루프린트와 연동 시 매개변수에 참조연산자를 쓰면 엔진버그가 발생
	
	void TestFunc(); //함수 선언 후 정의가 없으면 오류가 발생한다.

	UPROPERTY(BlueprintReadOnly, Category = "Practice")
		FString name;
};
