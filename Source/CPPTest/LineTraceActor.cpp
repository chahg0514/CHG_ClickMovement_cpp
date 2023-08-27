// Fill out your copyright notice in the Description page of Project Settings.

#include "LineTraceActor.h"

#include "CylinderActor.h" //���� ���� ����
#include "Kismet/GameplayStatics.h" //GetAllActors�� ����ϱ� ���� ���

#include "DrawDebugHelpers.h"

// Sets default values
ALineTraceActor::ALineTraceActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;
}

// Called when the game starts or when spawned
void ALineTraceActor::BeginPlay()
{
	Super::BeginPlay();
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACylinderActor::StaticClass(), Cylinders);
	//GetAllActorsOfClass : Ư�� Ŭ����Ÿ���� ���͸� ���忡�� ã�Ƽ� �迭�� �־���, �̷��� ���� �ΰ� ���忡 ��ġ�س����ϱ� �� �ΰ� ã�Ƽ� �迭�� �־���
}

// Called every frame
void ALineTraceActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector Start = Cylinders[0]->GetActorLocation(); //ù��° �Ǹ����� ��ġ�� ��ŸƮ������, �ι�°�� ���庯���� �־���
	FVector End = Cylinders[1]->GetActorLocation();

	{
		Start.Z -= 20;
		End.Z -= 20;
		DrawDebugLine(GetWorld(), Start, End, FColor::Yellow, false);

		//GEngine->AddOnScreenDebugMessage(-1, 0.1f, FColor::Cyan, FString::Printf(TEXT("MinusInside: %f"), Start.Z));
	}

	//GEngine->AddOnScreenDebugMessage(-1, 0.1f, FColor::Cyan, FString::Printf(TEXT("OutSide: %f"), Start.Z));
	{
		Start.Z += 20;
		End.Z += 20;
		//GEngine->AddOnScreenDebugMessage(-1, 0.1f, FColor::Cyan, FString::Printf(TEXT("PlusInSide: %f"), Start.Z));
		TArray<AActor*> IgnoreActors; // �浹�� ������ ����
		IgnoreActors.Add(Cylinders[0]);
		IgnoreActors.Add(Cylinders[1]);

		FHitResult HitResult; //�浹����� ���� ����ü
		UKismetSystemLibrary::LineTraceSingleByProfile(GetWorld(), Start, End, "Pawn", false, IgnoreActors, EDrawDebugTrace::ForOneFrame,
			HitResult, true, FLinearColor::Green, FLinearColor::Red);
		// ����Ʈ���̽� �߻�(����, ������, ������, �������̸�, Complex �˻� ����, �浹���þ���(�迭),����ǥ�ù��,
		//�浹���, �ڽ���������������,Ʈ���̼� ����, �浹�� Ʈ���̼� ����)
		if (HitResult.bBlockingHit)
		{
			GEngine->AddOnScreenDebugMessage(-1, 0.1f, FColor::Cyan, TEXT("Trace!"));
			//GEngine->AddOnScreenDebugMessage(-1, 0.1f, FColor::Cyan, FString::Printf(TEXT("%s"), HitResult.GetActor()->GetName()));
			
			
		}

	}

}

