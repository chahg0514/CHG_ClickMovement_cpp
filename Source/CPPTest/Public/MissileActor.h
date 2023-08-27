// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MissileActor.generated.h"

UCLASS()
class CPPTEST_API AMissileActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMissileActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	void SetActive(bool IsActive); //활성화 비활성화 함수
	void Deactivate(); //비활성화 함수
	bool isActive(); //활성화 비활성화 여부
	void FireInDirection(const FVector& Direction);
private:
	bool bActive; //활성화 비활성화 여부

	UPROPERTY(VisibleAnywhere, Category = "Missle")
		class UProjectileMovementComponent* Projectile;
	UPROPERTY(VisibleAnywhere, Category = "Missle")
		class UStaticMeshComponent* MyMesh;
	UPROPERTY(VisibleAnywhere, Category = "Missle")
		class USphereComponent* CollisionComp;

	FTimerHandle TimerHandle;

protected:
	virtual void NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal,
		FVector NormalImpulse, const FHitResult& Hit) override;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor)override;
private:
	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex, bool bFormSweep, const FHitResult& SweepResult);

};
