// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BehaviorTree/BehaviorTreeTypes.h"

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyAIController.generated.h"

//#include "BehaviorTree/BehaviorTreeTypes.h"


/**
 * 
 */
UCLASS()
class CPPTEST_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()
public:
	AEnemyAIController();
protected:
	virtual void OnPossess(APawn* InPawn) override;
private:
	UPROPERTY(VisibleAnywhere, Category = "AI")
		class UBehaviorTreeComponent* BehaviorComp;
	UPROPERTY(VisibleAnywhere, Category = "AI")
		class UBlackboardComponent* BlackboardComp;

	FBlackboard::FKey TargetKeyID;
	//�������� Key�� ID���� ������ �� �ִ� ����ü
	//����ü ���漱���� �ȵǹǷ�  ������Ͽ� #include�� ���־���.

public:
	FORCEINLINE FBlackboard::FKey GetTargetKey()
	{
		return TargetKeyID;
	}
	
};
