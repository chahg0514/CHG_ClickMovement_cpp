// Fill out your copyright notice in the Description page of Project Settings.


#include "EnumActor.h"

// Sets default values
AEnumActor::AEnumActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnumActor::BeginPlay()
{
	Super::BeginPlay();
	PlayerState = EPlayerState::MOVE;
	if (PlayerState == EPlayerState::IDLE)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Current is IDLE"));
	}
	
}

// Called every frame
void AEnumActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

