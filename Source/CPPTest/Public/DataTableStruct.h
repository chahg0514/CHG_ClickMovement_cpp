// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameFramework/Actor.h"
#include "DataTableStruct.generated.h" //�̰� �����̸����� �ϸ� ��

USTRUCT(BlueprintType)
struct FExpTable : public FTableRowBase //FTableRowBase �ڷ����� ��ӽ�����
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
	//������ �ִ� 1���� ������ �̸� ������ ������ ������ ������־�� �Ѵ�.
};

