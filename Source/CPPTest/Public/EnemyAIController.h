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
	//블랙보드의 Key의 ID값을 저장할 수 있는 구조체
	//구조체 전방선언이 안되므로  헤더파일에 #include를 해주었다.

public:
	FORCEINLINE FBlackboard::FKey GetTargetKey()
	{
		return TargetKeyID;
	}
	
};
