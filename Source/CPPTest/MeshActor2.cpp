// Fill out your copyright notice in the Description page of Project Settings.


#include "MeshActor2.h"

// Sets default values
AMeshActor2::AMeshActor2()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MyMesh2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyMesh2"));
	RootComponent = MyMesh2;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset2(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cylinder.Shape_Cylinder'"));
	if (MeshAsset2.Succeeded()) //경로에 문제가 없다면
	{
		MyMesh2->SetStaticMesh(MeshAsset2.Object); //여기까지가 메쉬의 액터를 지정하는 것
	}
}

// Called when the game starts or when spawned
void AMeshActor2::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMeshActor2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

