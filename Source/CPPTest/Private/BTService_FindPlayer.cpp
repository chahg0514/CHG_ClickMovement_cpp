// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_FindPlayer.h"

#include "EnemyAIController.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Object.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"

#include "BTService_FindPlayer.h"


UBTService_FindPlayer::UBTService_FindPlayer()
{
	bCreateNodeInstance = true;
	//노드 고유의 인스턴스를 사용
	//일정량의 포퍼먼스를 포기하고 메모리를 사용하여 데이터를 안전하게 사용 가능
}

void UBTService_FindPlayer::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
	AEnemyAIController* AIOwner = Cast<AEnemyAIController>(OwnerComp.GetAIOwner());
	if (AIOwner != nullptr)
	{
		APawn* Player = GetWorld()->GetFirstPlayerController()->GetPawn(); //월드의 플레이어를 가져옴
		OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Object>(AIOwner->GetTargetKey(),Player);
		//TargetKey에 Player를 저장

	}
}
