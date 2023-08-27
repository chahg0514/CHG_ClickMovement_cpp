// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "FirstGameMode.generated.h"

/**
 * 
 */
UCLASS()
class CPPTEST_API AFirstGameMode : public AGameModeBase
{
	GENERATED_BODY()
public: 
	virtual void BeginPlay() override;
private: 
	UPROPERTY(VisibleAnywhere, Category = "MeshActor")
		class AMeshActor* MyMeshActor;
	UPROPERTY(VisibleAnywhere, Category = "MeshActor")
		class ACubeActor* MyMeshActor23; //굳이 포인터로 만드는 이유는..?

private:
	UFUNCTION()
		void MyMeshActorDestroy();
private:
	UPROPERTY(VisibleAnywhere, Category = "MeshActor")
		class ACubeActor* MyMeshActor2;
	UPROPERTY(VisibleAnywhere, Category = "MeshActor")
		class AMeshActor* MyMeshActor3;
	UPROPERTY(VisibleAnywhere, Category = "MeshActor")
		class ACubeActor* whywhy;
};
