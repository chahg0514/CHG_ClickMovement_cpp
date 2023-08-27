// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LineTraceActor.generated.h"

UCLASS()
class CPPTEST_API ALineTraceActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALineTraceActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:
	UPROPERTY(VisibleDefaultsOnly, Category = "MyTrace")
		class USceneComponent* Root;
	UPROPERTY(VisibleDefaultsOnly, Category = "MyTrace")
		TArray<class AActor*> Cylinders; //�迭

};
