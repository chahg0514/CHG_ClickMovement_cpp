// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DebugDrawActor.generated.h"

UCLASS()
class CPPTEST_API ADebugDrawActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADebugDrawActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "DrawDebug")
		FVector InitLocation[5];
	UPROPERTY(EditAnywhere, Category = "DrawDebug")
		FBox Box; //FBox : ������ü�� ������ �����ϴ� ����ü
	UPROPERTY(EditAnywhere, Category = "DrawDebug")
		FTransform Transform;
	UPROPERTY(EditAnywhere, Category = "DrawDebug")
		FVector Location[5];
	UPROPERTY(EditAnywhere, Category = "DrawDebug")
		USceneComponent* Root;
	//USceneComponent : Transform ������ ������ ������Ʈ

};
