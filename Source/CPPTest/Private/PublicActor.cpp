// Fill out your copyright notice in the Description page of Project Settings.


#include "PublicActor.h"

#include "PrivateActor.h" //이렇게 private도 추가는 가능하다..?

#include "WidgetsActor.h"

// Sets default values
APublicActor::APublicActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void APublicActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APublicActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

