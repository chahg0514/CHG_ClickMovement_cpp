// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAIController.h"
#include "BehaviorTree/BehaviorTree.h" 
#include "BehaviorTree/BehaviorTreeComponent.h" 
#include "BehaviorTree/BlackboardComponent.h" 
#include "EnemyCharacter.h"

AEnemyAIController::AEnemyAIController()
{
	BehaviorComp = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorComp"));
	
	BlackboardComp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComp"));
}

void AEnemyAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	
	
	AEnemyCharacter* Enemy = Cast<AEnemyCharacter>(InPawn); //연결된 폰을 형변환해서 넣어줌
	if (IsValid(Enemy))
	{
		if (Enemy->GetEnemyBehavior() != nullptr)
		{
			BlackboardComp->InitializeBlackboard(*Enemy->GetEnemyBehavior()->BlackboardAsset);
			//블랙보드 초기화
			TargetKeyID = BlackboardComp->GetKeyID("Target");
			//블랙보드에 저장된 Target키값을 저장
			BehaviorComp->StartTree(*Enemy->GetEnemyBehavior());
			//비헤이비어 트리 시작
		}
	}
}
