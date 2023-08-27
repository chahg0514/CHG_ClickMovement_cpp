// Fill out your copyright notice in the Description page of Project Settings.

#include "LineTraceActor.h"

#include "CylinderActor.h" //내가 만든 액터
#include "Kismet/GameplayStatics.h" //GetAllActors를 사용하기 위한 헤더

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
	//GetAllActorsOfClass : 특정 클래스타입의 액터를 월드에서 찾아서 배열에 넣어줌, 이러면 내가 두개 월드에 설치해놨으니까 그 두개 찾아서 배열에 넣어줌
}

// Called every frame
void ALineTraceActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector Start = Cylinders[0]->GetActorLocation(); //첫번째 실린더의 위치를 스타트변수에, 두번째를 엔드변수에 넣어줌
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
		TArray<AActor*> IgnoreActors; // 충돌을 무시할 액터
		IgnoreActors.Add(Cylinders[0]);
		IgnoreActors.Add(Cylinders[1]);

		FHitResult HitResult; //충돌결과를 담을 구조체
		UKismetSystemLibrary::LineTraceSingleByProfile(GetWorld(), Start, End, "Pawn", false, IgnoreActors, EDrawDebugTrace::ForOneFrame,
			HitResult, true, FLinearColor::Green, FLinearColor::Red);
		// 라인트레이스 발사(월드, 시작점, 끝지점, 프로필이름, Complex 검사 여부, 충돌무시액터(배열),광선표시방법,
		//충돌결과, 자신을무시할지여부,트레이서 색상, 충돌시 트레이서 색상)
		if (HitResult.bBlockingHit)
		{
			GEngine->AddOnScreenDebugMessage(-1, 0.1f, FColor::Cyan, TEXT("Trace!"));
			//GEngine->AddOnScreenDebugMessage(-1, 0.1f, FColor::Cyan, FString::Printf(TEXT("%s"), HitResult.GetActor()->GetName()));
			
			
		}

	}

}

