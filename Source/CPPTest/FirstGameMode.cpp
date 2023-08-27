// Fill out your copyright notice in the Description page of Project Settings.


#include "FirstGameMode.h"
#include "MeshActor.h"
#include "CubeActor.h"

void AFirstGameMode::BeginPlay()
{
	Super::BeginPlay();

	FTransform SpawnLocation; //트랜스폼 정보를 만들어줌
	GetWorld()->SpawnActor<AMeshActor>
		(AMeshActor::StaticClass(), SpawnLocation);
	//GetWorld(): 현재 월드를 반환
	//SpawnActor: 액터를 생성
	//StaticClass(): 클래스 타입을 반환..? 이해 안됨

	FTransform SpawnTransform;
	SpawnTransform.SetLocation(FVector(200, 0, 0));

	MyMeshActor = GetWorld()->SpawnActor<AMeshActor>(AMeshActor::StaticClass(), SpawnTransform);
	FTimerHandle Timer; //타이머를 구별할 수 있는 핸들
	//핸들: 운영체제의 원하는 리소스 주소를 정수로 치환한 값, 리소스 주소라고 보면 됨
	
	GetWorldTimerManager().SetTimer(Timer, this, &AFirstGameMode::MyMeshActorDestroy, 10);
	//MyMeshActorDestroy함수를 10초 후에 호출한다는 의미

	SpawnLocation.SetLocation(FVector(400, 0, 0));
	MyMeshActor2 = GetWorld()->SpawnActor<ACubeActor>(ACubeActor::StaticClass(), SpawnLocation);
	MyMeshActor2->SetLifeSpan(5.f);
	//SetLifeSpan: 일정시간 후 액터 제거

	SpawnLocation.SetLocation(FVector(600, 0, 0));
	MyMeshActor3 = GetWorld()->SpawnActor<AMeshActor>(AMeshActor::StaticClass(), SpawnLocation); 
	//지역변수 이걸로 하면 안지워질뿐만아니라 튕긴다. 헤더파일에서 선언한걸로 해야 잘 지워짐..

	FTimerHandle Timer2;
	GetWorld()->GetTimerManager().SetTimer(Timer2, FTimerDelegate::CreateLambda([&]()
		{
			MyMeshActor3->Destroy();
		}), 15.f, false); //15초 후 람다함수를 호출함. 람다함수를 이용하여 일정시간 후 함수 호출, true 넣으면 반복, false는 한번만
}

void AFirstGameMode::MyMeshActorDestroy()
{
	if (MyMeshActor != nullptr)
	{
		MyMeshActor->Destroy();
		//가비지가 뭐 해준다고 했는데 7시 11분
	}
}
