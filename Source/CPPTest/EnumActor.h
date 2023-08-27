// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnumActor.generated.h"

UENUM(BlueprintType) //�������� �𸮾� ��� �� �������Ʈ ��� ����
enum class EPlayerState : uint8
{
	//�������� ������ �� ���� �̸� �տ� E�� ���δ�
	//uint8: ���� ������ 8bit
	//�������� uint8�� ����Ѵٴ� �ǹ�
	//�������� uint8�� �����Ѵ�.
	IDLE UMETA(DisplayName = "idle"),
	MOVE UMETA(DisplayName = "move"),
	RUN UMETA(DisplayName = "run"),
	ATTACK UMETA(DisplayName = "attack")
	//DisplayName: �ܺο��� ������ �̸�
	//c++���� �빮�ڷ� ����, �������Ʈ���� �ҹ��ڷ� ��. ������ �ƴ� �׳� �������Ʈ������ �빮�ڷ� �ص� �ǰ� c++���� �ҹ��ڷ� �ص� �����̻��� �ƴ�

};

UCLASS()
class CPPTEST_API AEnumActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnumActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State") //��𼭵� �����ְ� �������Ʈ���� ��� ����
		EPlayerState PlayerState; //������ ���� ����

};
