// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MeshActor.generated.h"

UCLASS()
class CPPTEST_API AMeshActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMeshActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:
	UPROPERTY(VisibleAnywhere, Category = "MyMesh")
	class UStaticMeshComponent* MyMesh; //Mesh�� �����ͷ� ��������
	//UObject�� ��ӹ޴� Ŭ������ UPROPERTY�� �־ �𸮾� ��Ͻ��Ѿ� �Ѵ�(������ �÷������� �����ϱ�����)
	//������Ʈ�� Visible, Edit + DefaultsOnly,Anywhere�� �־�� �Ѵ�.(�浹�� �Ͼ �� �ֱ� ����)
	//�𸮾� 4.22 ������ ���������� Visible�� ����ؾ� �Ѵ�.

};
