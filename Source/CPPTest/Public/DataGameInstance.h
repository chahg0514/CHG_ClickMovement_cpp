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
public: //�����ڶ� ���� �Լ��� �����ϱ� ���� �ۺ� �ΰ��� ����
	UDataGameInstance(); //�̰� �����ߴ��� �ٽ� Ȯ���غ��� (���Ӹ��?�����Ű�����)
public:
	struct FExpTable* GetDataTable(int32 RowName);//����ü ���漱��
private: //���������ڴ� �ۺ�=>������Ƽ��=>�����̺�
	UPROPERTY(VisibleAnywhere, Category = "ExpData")
		class UDataTable* ExpTable; //���������̺��� ���� �� �ִ� �ڷ������� ���� ����
	
	
};
