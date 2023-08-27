// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "OverlapActor.generated.h"

UCLASS()
class CPPTEST_API AOverlapActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AOverlapActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
protected:
	virtual void NotifyActorBeginOverlap(AActor* OtherActor)override; //겹침으로 충돌 시작시 호출되는 함수
	virtual void NotifyActorEndOverlap(AActor* OtherActor)override;

private:
	UPROPERTY(VisibleAnywhere, Category = "MyMesh")
		class UStaticMeshComponent* MyMesh; //클래스 전방선언

};
