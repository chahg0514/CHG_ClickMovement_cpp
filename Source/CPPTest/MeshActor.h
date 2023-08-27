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
	class UStaticMeshComponent* MyMesh; //Mesh를 포인터로 변수선언
	//UObject를 상속받는 클래스는 UPROPERTY를 넣어서 언리얼에 등록시켜야 한다(가비지 컬렉션으로 관리하기위함)
	//컴포넌트는 Visible, Edit + DefaultsOnly,Anywhere를 넣어야 한다.(충돌이 일어날 수 있기 때문)
	//언리얼 4.22 이하의 버전에서는 Visible만 사용해야 한다.

};
