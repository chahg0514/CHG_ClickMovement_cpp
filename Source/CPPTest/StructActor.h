// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "StructActor.generated.h"

USTRUCT(BlueprintType) //�𸮾� ���, �������Ʈ ����ϵ���
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

//�𸮾� ���̹� ��Ģ
//Ŭ���� Ȥ�� �����̸� �տ� Ư���ܾ ���δ�.
// - U : UObject�� ��ӹ��� Ŭ���� (�𸮾� �ֻ�� ObjectŬ���� �װ���)
// - A : UObject�� ��ӹ޾Ҵµ��� A��. AActor�� ��ӹ��� Ŭ���� (Pawn, Character ��)
// - F : �� �̿� ��� Ŭ���� �� ����ü(FString ���)
// - T : ���ø�(TArray,TMap)
// - I : �������̽�
// - E : ������
// - b : bool�� ����
//
