// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ClickMoveCharacter.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnEnemyActor.generated.h"

UCLASS()
class CPPTEST_API ASpawnEnemyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnEnemyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(VisibleAnywhere, Category = "Spawn")
		int32 random;
private:
	UPROPERTY(VisibleAnywhere, Category = "Spawn")
		AClickMoveCharacter* player;
	FTimerHandle TimerHandle;

public:
	void KeepSpawn();
};
