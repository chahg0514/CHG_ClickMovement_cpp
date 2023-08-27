// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ClickMoveCharacter.h"


/**
 * 
 */
class CPPTEST_API SpawnEnemy 
{
	
public:
	SpawnEnemy();
	~SpawnEnemy();
public:
	AClickMoveCharacter* player;
	
	//UFUNCTION()
		//virtual void BeginPlay() override;
private:
	FTimerHandle TimerHandle;

	UFUNCTION()
	void KeepSpawn();

	UPROPERTY(VisibleAnywhere,Category = "SpawnEnemy")
		int32 random;
	UPROPERTY(VisibleAnywhere, Category = "SpawnEnemy")
	UWorld* WorldRef;
	UPROPERTY(VisibleAnywhere, Category = "SpawnEnemy")
	AActor* ActorRef;
};
