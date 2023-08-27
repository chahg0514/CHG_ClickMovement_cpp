// Fill out your copyright notice in the Description page of Project Settings.


#include "CHGActor.h"

// Sets default values
ACHGActor::ACHGActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACHGActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACHGActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

