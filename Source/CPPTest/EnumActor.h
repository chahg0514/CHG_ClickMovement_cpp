// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnumActor.generated.h"

UENUM(BlueprintType) //열거형을 언리얼에 등록 및 블루프린트 사용 가능
enum class EPlayerState : uint8
{
	//열거형은 정의할 때 변수 이름 앞에 E를 붙인다
	//uint8: 양의 정수형 8bit
	//열거형에 uint8을 사용한다는 의미
	//열거형은 uint8만 지원한다.
	IDLE UMETA(DisplayName = "idle"),
	MOVE UMETA(DisplayName = "move"),
	RUN UMETA(DisplayName = "run"),
	ATTACK UMETA(DisplayName = "attack")
	//DisplayName: 외부에서 보여질 이름
	//c++에선 대문자로 쓰고, 블루프린트에선 소문자로 씀. 정답은 아님 그냥 블루프린트에서도 대문자로 해도 되고 c++에서 소문자로 해도 문법이상은 아님

};

UCLASS()
class CPPTEST_API AEnumActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnumActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State") //어디서든 보여주고 블루프린트에서 사용 가능
		EPlayerState PlayerState; //열거형 변수 선언

};
