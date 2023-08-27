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
	//������Ʈ�� ��ħ���� �浹 �� ȣ��Ǵ� ��������Ʈ�� ����� �Լ�
private:
	UPROPERTY(VisibleAnywhere, Category = "BeginOverlap")
		class USphereComponent* SphereCollision;
	//USphereComponent : ��ü�� �ݸ��� ������Ʈ
	UPROPERTY(VisibleAnywhere, Category = "BeginOverlap")
		class UStaticMeshComponent* MyMesh;
	UPROPERTY(VisibleAnywhere, Category = "beginOverlap")
		class UParticleSystem* Particle;

};
