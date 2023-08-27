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
	//FindRow: 데이터 테이블의 행(가로)을 찾음, RowName에 1을 넣으면 첫번째 가로줄 데이터 반환
	//FindRow<찾을데이터테이블자료형>(찾을 이름 행, 못찾았을 때 출력할 문자열)
}
