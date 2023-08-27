// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "FirstSaveGame.generated.h"

//저장할 데이터 구조체
USTRUCT(BlueprintType)
struct FSaveGameStruct
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "SaveData")
		int32 StructInteger;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "SaveData")
		float StructFloat;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "SaveData")
		FVector StructVector;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "SaveData")
		FString StructString;
};

/**
 * 
 */
UCLASS()
class CPPTEST_API UFirstSaveGame : public USaveGame
{
	GENERATED_BODY()
public:
	//저장할 것들 선언..?
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "SaveData")
		FString SaveSlotName = TEXT("TestSave"); //저장할 파일명
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "SaveData")
		int32 SaveIndex = 0; //저장할 파일 인덱스
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "SaveData")
		FSaveGameStruct SaveStruct; //저장할 구조체
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "SaveData")
		TArray<int32> SaveTArray; //저장할 배열
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "SaveData")
		FName SaveName; //저장할 Name변수
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "SaveData")
		FTransform SaveTransform; //저장할 트랜스폼
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "SaveData")
		float SaveFloat; //저장할 float 변수

	
	
};
