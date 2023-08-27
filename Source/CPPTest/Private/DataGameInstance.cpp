// Fill out your copyright notice in the Description page of Project Settings.


#include "DataGameInstance.h"
#include "DataTableStruct.h"

UDataGameInstance::UDataGameInstance()
{
	static ConstructorHelpers::FObjectFinder<UDataTable> DataAsset(TEXT("DataTable'/Game/DataTable/LevelUpExpTable_xlsx.LevelUpExpTable_xlsx'"));
	if (DataAsset.Succeeded())
	{
		ExpTable = DataAsset.Object;
	}
	GetDataTable(1);
}

FExpTable* UDataGameInstance::GetDataTable(int32 RowName)
{
	return ExpTable->FindRow<FExpTable>(*FString::FromInt(RowName),TEXT("NotFineRow"));
	//FindRow: ������ ���̺��� ��(����)�� ã��, RowName�� 1�� ������ ù��° ������ ������ ��ȯ
	//FindRow<ã�����������̺��ڷ���>(ã�� �̸� ��, ��ã���� �� ����� ���ڿ�)
}
