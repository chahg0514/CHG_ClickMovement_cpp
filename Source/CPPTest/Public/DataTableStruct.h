// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameFramework/Actor.h"
#include "DataTableStruct.generated.h" //이건 파일이름으로 하면 됨

USTRUCT(BlueprintType)
struct FExpTable : public FTableRowBase //FTableRowBase 자료형을 상속시켜줌
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 Level;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 NextExp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 TotalExp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		float Atk;
	//엑셀에 있는 1열과 동일한 이름 동일한 순서로 변수를 만들어주어야 한다.
};

