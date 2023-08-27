// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "StructActor.generated.h"

USTRUCT(BlueprintType) //언리얼에 등록, 블루프린트 사용하도록
struct FUnitTest
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unit")
		int32 Level;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unit")
		float Damage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unit")
		FString UnitName;

};

UCLASS()
class CPPTEST_API AStructActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AStructActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Unit")
		FUnitTest UnitTest;

};

//언리얼 네이밍 규칙
//클래스 혹은 변수이름 앞에 특정단어를 붙인다.
// - U : UObject를 상속받은 클래스 (언리얼 최상단 Object클래스 그거임)
// - A : UObject를 상속받았는데도 A임. AActor를 상속받은 클래스 (Pawn, Character 등)
// - F : 그 이외 모든 클래스 및 구조체(FString 등등)
// - T : 템플릿(TArray,TMap)
// - I : 인터페이스
// - E : 열거형
// - b : bool형 변수
//
