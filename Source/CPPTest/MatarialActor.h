// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MatarialActor.generated.h"

UCLASS()
class CPPTEST_API AMatarialActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMatarialActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:
	UPROPERTY(VisibleDefaultsOnly, Category = "MaterialTest")
		class UStaticMeshComponent* Mesh;
	UPROPERTY(VisibleDefaultsOnly, Category = "MaterialTest")
		class UMaterialInstanceDynamic* Material;
private:
	UFUNCTION()
		void ChangeColor();


};

// *��Ƽ���� �ν��Ͻ�
// ��Ƽ���� �ν��Ͻ��� "��Ƽ���� �ν��Ͻ� �ܽ��Ͻ��� ��Ƽ���� �ν��Ͻ� ���̳��� �ΰ����� �ִ�.
//

//* ��Ƽ���� �ν��Ͻ� �ܽ���Ʈ(�Ķ���� ������ ���� ���� �� ���� �Ұ���)
//������ �ѹ��� ������ ���ӽ��� �� ������ �Ұ����ϴ�.
//������ �ѹ��� �����ϵǹǷ� �����ս����� ������ �ִ�.

//* ��Ƽ���� �ν��Ͻ� ���̳���
//���� ���� ���߿� ���� ������ �� �ִ�.