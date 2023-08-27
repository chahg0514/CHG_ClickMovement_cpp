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
	AClickMovePlayerController(); //������
protected:
	virtual void PlayerTick(float DeltaTime) override;
	//��Ʈ�ѷ� ƽ�Լ�
	virtual void SetupInputComponent() override;
	//�Է��� �޴� �Լ�
	virtual void BeginPlay() override;
private:
	void GetMouseButtonDown();
	void GetMouseButtonUp();
	void SetDestination(const FVector Destination);
	void MoveToMouseCursor();

private:
	bool isClick; //Ŭ�� ����
	UPROPERTY(VisibleAnywhere, Category = "ObjectPool")
		TArray<class AShotActor*> Bullet;
	UPROPERTY(VisibleAnywhere, Category = "ObjectPool")
		TArray<class AMissileActor*> Missile;

protected:
	void Shot();
protected:
	void MissileAttack();

	
};
