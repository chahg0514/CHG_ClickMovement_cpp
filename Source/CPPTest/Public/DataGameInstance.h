// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "DataGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class CPPTEST_API UDataGameInstance : public UGameInstance
{
	GENERATED_BODY()
public: //생성자랑 만든 함수랑 구분하기 위해 퍼블릭 두개로 나눔
	UDataGameInstance(); //이거 생성했던거 다시 확인해보기 (게임모드?였던거같은데)
public:
	struct FExpTable* GetDataTable(int32 RowName);//구조체 전방선언
private: //접근지정자는 퍼블릭=>프로텍티드=>프라이빗
	UPROPERTY(VisibleAnywhere, Category = "ExpData")
		class UDataTable* ExpTable; //데이터테이블을 넣을 수 있는 자료형으로 변수 생성
	
	
};
