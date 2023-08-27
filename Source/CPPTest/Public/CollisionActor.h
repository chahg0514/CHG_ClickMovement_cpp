// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CollisionActor.generated.h"

UCLASS()
class CPPTEST_API ACollisionActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACollisionActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
protected:
	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
			const FHitResult& SweepResult);
	//컴포넌트의 겹침으로 충돌 시 호출되는 델리게이트와 연결될 함수
private:
	UPROPERTY(VisibleAnywhere, Category = "BeginOverlap")
		class USphereComponent* SphereCollision;
	//USphereComponent : 구체의 콜리전 컴포넌트
	UPROPERTY(VisibleAnywhere, Category = "BeginOverlap")
		class UStaticMeshComponent* MyMesh;
	UPROPERTY(VisibleAnywhere, Category = "beginOverlap")
		class UParticleSystem* Particle;

};
