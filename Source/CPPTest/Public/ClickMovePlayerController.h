// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ClickMovePlayerController.generated.h"

/**
 * 
 */
UCLASS()
class CPPTEST_API AClickMovePlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	AClickMovePlayerController(); //생성자
protected:
	virtual void PlayerTick(float DeltaTime) override;
	//컨트롤러 틱함수
	virtual void SetupInputComponent() override;
	//입력을 받는 함수
	virtual void BeginPlay() override;
private:
	void GetMouseButtonDown();
	void GetMouseButtonUp();
	void SetDestination(const FVector Destination);
	void MoveToMouseCursor();

private:
	bool isClick; //클릭 여부
	UPROPERTY(VisibleAnywhere, Category = "ObjectPool")
		TArray<class AShotActor*> Bullet;
	UPROPERTY(VisibleAnywhere, Category = "ObjectPool")
		TArray<class AMissileActor*> Missile;

protected:
	void Shot();
protected:
	void MissileAttack();

	
};
