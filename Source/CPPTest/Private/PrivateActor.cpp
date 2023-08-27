// Fill out your copyright notice in the Description page of Project Settings.


#include "PrivateActor.h"

// Sets default values
APrivateActor::APrivateActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APrivateActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APrivateActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

