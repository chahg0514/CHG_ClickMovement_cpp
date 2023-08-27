// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnemyCharacter.generated.h"

UCLASS()
class CPPTEST_API AEnemyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
private:
	UPROPERTY(VisibleAnywhere, Category = "Enemy")
		class UStaticMeshComponent* MyMesh;
	UPROPERTY(VisibleAnywhere, Category = "Enemy")
		class UBehaviorTree* EnemyBehaviorTree;

public:
	UFUNCTION()
		FORCEINLINE UBehaviorTree* GetEnemyBehavior()
	{
		return EnemyBehaviorTree;
	}
	//FORCEINLINE : 언리얼 인라인함수
	//C++ 인라인 함수보다 강제적이다.

};
