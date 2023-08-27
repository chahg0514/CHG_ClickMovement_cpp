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
	//��� ������ �ν��Ͻ��� ���
	//�������� ���۸ս��� �����ϰ� �޸𸮸� ����Ͽ� �����͸� �����ϰ� ��� ����
}

void UBTService_FindPlayer::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
	AEnemyAIController* AIOwner = Cast<AEnemyAIController>(OwnerComp.GetAIOwner());
	if (AIOwner != nullptr)
	{
		APawn* Player = GetWorld()->GetFirstPlayerController()->GetPawn(); //������ �÷��̾ ������
		OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Object>(AIOwner->GetTargetKey(),Player);
		//TargetKey�� Player�� ����

	}
}
