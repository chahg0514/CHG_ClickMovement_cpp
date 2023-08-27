// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PublicActor.generated.h"

UCLASS()
class CPPTEST_API APublicActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APublicActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
// * 모듈폴더관리
// 언리얼의 모듈에서는 3개의 폴더로 구성된다.
// Public: 외부 모듈에 공개할 파일
// Private: 내부 모듈에 사용할 파일
// Classes: 언리얼 오브젝트 관련 헤더 파일

// 헤더는 Public, 소스파일은 Private폴더로 저장
// cpp파일은 멤버함수 정의용도이므로
// 외부에서 include하지 않으므로 private폴더에 넣어둔다.

// * 모듈 추가 규칙
// 모듈이름과 동일한 폴더가 필요하다.
// 모듈의 빌드 규칙파일: 모듈이름.Build.cs
// 모듈명 헤더, 소스파일: 모듈이름.h, 모듈이름.cpp 이렇게 총 4가지가 필요한 것이다(폴더 + 3가지)
// Widgets라는 이름으로 모듈 만들기 해봄
