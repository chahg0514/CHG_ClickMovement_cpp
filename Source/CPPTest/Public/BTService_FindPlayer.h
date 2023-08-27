// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BTService_FindPlayer.generated.h"

/**
 * 
 */
UCLASS()
class CPPTEST_API UBTService_FindPlayer : public UBTService
{
	GENERATED_BODY()
public:
	UBTService_FindPlayer();
protected:
	virtual void TickNode(class UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override; //서비스 틱함수
	
};
