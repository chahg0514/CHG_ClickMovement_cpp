// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "FirstSaveGame.generated.h"

//������ ������ ����ü
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
	//������ �͵� ����..?
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "SaveData")
		FString SaveSlotName = TEXT("TestSave"); //������ ���ϸ�
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "SaveData")
		int32 SaveIndex = 0; //������ ���� �ε���
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "SaveData")
		FSaveGameStruct SaveStruct; //������ ����ü
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "SaveData")
		TArray<int32> SaveTArray; //������ �迭
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "SaveData")
		FName SaveName; //������ Name����
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "SaveData")
		FTransform SaveTransform; //������ Ʈ������
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "SaveData")
		float SaveFloat; //������ float ����

	
	
};
