// Fill out your copyright notice in the Description page of Project Settings.


#include "DataSaveActor.h"

#include "FirstSaveGame.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ADataSaveActor::ADataSaveActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADataSaveActor::BeginPlay()
{
	Super::BeginPlay();
	DataSave();
	DataLoad();
	
}

// Called every frame
void ADataSaveActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADataSaveActor::DataSave()
{
	UFirstSaveGame* SaveData = Cast<UFirstSaveGame>(UGameplayStatics::CreateSaveGameObject(UFirstSaveGame::StaticClass()));
	//FirstSaveGame Ŭ���� ����
	if (!!SaveData)
	{
		SaveData->SaveName = FName(TEXT("Player"));
		SaveData->SaveFloat = 12.34f;
		SaveData->SaveTArray.Add(3);
		SaveData->SaveTArray.Add(101);
		SaveData->SaveTransform = FTransform(FVector(5, 10, 15));
		SaveData->SaveStruct.StructInteger = 123;
		SaveData->SaveStruct.StructString = TEXT("Unreal");

		UGameplayStatics::SaveGameToSlot(SaveData, SaveData->SaveSlotName, SaveData->SaveIndex);
		//SaveGameToSlot(������ ������ Ŭ����, �����̸�, ���� �ε���)

	}
}

void ADataSaveActor::DataLoad()
{
	UFirstSaveGame* LoadData = Cast<UFirstSaveGame>(UGameplayStatics::CreateSaveGameObject(UFirstSaveGame::StaticClass()));
	if (LoadData != nullptr)
	{
		LoadData = Cast<UFirstSaveGame>(UGameplayStatics::LoadGameFromSlot(LoadData->SaveSlotName, LoadData->SaveIndex));
		//������ �ҷ�����

		//UE_LOG(LogTemp, Warning, TEXT("%s"), *LoadData->SaveName.ToString());
		UE_LOG(LogTemp, Warning, TEXT("SaveName : %s"), *LoadData->SaveName.ToString());
		UE_LOG(LogTemp, Warning, TEXT("SaveFloat : %f"), LoadData->SaveFloat);
		UE_LOG(LogTemp, Warning, TEXT("SaveTransform : %s"), *LoadData->SaveTransform.ToString());
		UE_LOG(LogTemp, Warning, TEXT("SaveTArray[1] : %d"), LoadData->SaveTArray[1]);
	}
}

