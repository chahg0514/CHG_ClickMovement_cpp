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
		 FVector NormalImpulse, const FHitResult& Hit) override; //블록상태로 충돌시 호출되는 함수

	//*UPrimitiveComponent
	// => USceneComonent의 자식클래스(씬컴포넌트는 트랜스폼만 가지고 있다. 이거의 자식은 트랜스폼정보를 가지고있다는 뜻)
	// => Collision 데이터로 사용되거나 Rendering Geometry 유형을 생성하거나 담는 컴포넌트
	// => 즉 랜더링(3D모델을 화면에 보여주는)이나 충돌을 위한 형상을 가진 컴포넌트
private:
	UPROPERTY(VisibleAnywhere, Category = "MyMesh")
		class UStaticMeshComponent* MyMesh; //클래스 전방선언

};
