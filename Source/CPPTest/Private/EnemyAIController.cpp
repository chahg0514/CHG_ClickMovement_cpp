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
	
	
	AEnemyCharacter* Enemy = Cast<AEnemyCharacter>(InPawn); //����� ���� ����ȯ�ؼ� �־���
	if (IsValid(Enemy))
	{
		if (Enemy->GetEnemyBehavior() != nullptr)
		{
			BlackboardComp->InitializeBlackboard(*Enemy->GetEnemyBehavior()->BlackboardAsset);
			//������ �ʱ�ȭ
			TargetKeyID = BlackboardComp->GetKeyID("Target");
			//�����忡 ����� TargetŰ���� ����
			BehaviorComp->StartTree(*Enemy->GetEnemyBehavior());
			//�����̺�� Ʈ�� ����
		}
	}
}
