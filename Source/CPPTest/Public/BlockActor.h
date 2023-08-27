// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BlockActor.generated.h"

UCLASS()
class CPPTEST_API ABlockActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABlockActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal,
		 FVector NormalImpulse, const FHitResult& Hit) override; //��ϻ��·� �浹�� ȣ��Ǵ� �Լ�

	//*UPrimitiveComponent
	// => USceneComonent�� �ڽ�Ŭ����(��������Ʈ�� Ʈ�������� ������ �ִ�. �̰��� �ڽ��� Ʈ������������ �������ִٴ� ��)
	// => Collision �����ͷ� ���ǰų� Rendering Geometry ������ �����ϰų� ��� ������Ʈ
	// => �� ������(3D���� ȭ�鿡 �����ִ�)�̳� �浹�� ���� ������ ���� ������Ʈ
private:
	UPROPERTY(VisibleAnywhere, Category = "MyMesh")
		class UStaticMeshComponent* MyMesh; //Ŭ���� ���漱��

};
