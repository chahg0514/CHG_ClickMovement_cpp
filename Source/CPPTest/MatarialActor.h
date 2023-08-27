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

// *머티리얼 인스턴스
// 머티리얼 인스턴스는 "머티리얼 인스턴스 콘스턴스와 머티리얼 인스턴스 다이나믹 두가지가 있다.
//

//* 머티리얼 인스턴스 콘스턴트(파라미터 노드들을 게임 실행 중 변경 불가능)
//실행전 한번만 계사뇌며 게임실행 중 변경이 불가능하다.
//하지만 한번만 컴파일되므로 퍼포먼스상의 이점이 있다.

//* 머티리얼 인스턴스 다이나믹
//게임 실행 도중에 값을 변경할 수 있다.