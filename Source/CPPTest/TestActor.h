// Fill out your copyright notice in the Description page of Project Settings.

//리플렉션 시스템 이용 조건
// 클래스이름.generated.h 파일이 include 되어있어야 함(현재 되어있음)
// 클래스위에 UCLASS() 매크로 사용되어있어야 함(현재 사용됨)
// 클래스 내부 GENERATED_BODY 매크로가 사용되어있어야 함(현재 사용됨)
// 멤버 변수는 UPROPERTY() 매크로가 사용해야 함
// 멤버 함수는 UFUCTION() 매크로 사용해야함
// 
// 가비지 컬렉션
// 리플렉션기능을 활용하여 언리얼이 만든 기능
// 코드를 통해 동적으로 할당했던 메모리 영역 중에서 어떤 변수도 가리키지 않는 영역을 해제해 주는 기능
// UObject와 그의 자식객체에 한해서만 가비지 컬렉션을 실행
// 기능을 사용하기 위해선 UPROPERTY() 매크로를 사용해야 한다
//


#pragma once //헤더의 중복선언 오류 방지

#include "CoreMinimal.h" //언리얼의 최소한의 핵심기능을 모아둔 헤더파일
#include "GameFramework/Actor.h" //Actor를 상속받으므로 Actor 헤더파일
#include "TestActor.generated.h" //관련 변수들을 Blueprint화 해주는 헤더파일

UCLASS() //클래스를 언리얼에 등록시켜주는 매크로(언리얼에 이 클래스가 있다고 알려주는 역할이라고 보면 됨)
class CPPTEST_API ATestActor : public AActor
{
	GENERATED_BODY() 
		//언리얼 타입 시스템에 필요한 기능이 포함된 매크로
		//위에 함수나 변수를 선언하면 오류난다.
	
public:	
	// Sets default values for this actor's properties
	ATestActor();//생성자
	//클래스 객체가 생성될 때 1회 호출
	//기본값을 설정하는 데 사용

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	//게임 시작시, 혹은 게임 중 생성 시 1회 호출

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	//매 프레임마다 호출

	//UPROPERTY
	// 변수를 언리얼에 등록시키는 매크로
	// 
	//접두사(앞에)
	//Edit : 변수를 보여주며 수정 가능
	//Visible: 변수를 보여주며 수정 불가능
	//접미사(뒤에)
	//Anywhere:어디에서든
	//DefaultOnly: 블루프린트 에디터에서
	//InstanceOnly: 레벨에 배치된 오브젝트에서

	UPROPERTY(EditAnywhere, Category = "Test") //언리얼에 등록시켜주는 매크로, 괄호 안은 인스턴스 편집 가능, 카테고리는 블루프린트에서랑 기능 같음
		int32 CurrentHP;
	UPROPERTY(VisibleInstanceOnly, Category = "Test")
		FString MyName;
	//블루프린트 공개
	//BlueprintReadWrite : 블루프린트에 읽고 수정 가능
	//BlueprintReadOnly: 블루프린트에서 읽기만 가능
	//블루프린트 만들면 이게 부모클래스가 되는거임 그건 자식
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "MyFirstCpp")
		int32 MaxHP;
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "MyFirstCpp")
		float CurrentTime;

	//int형
	// int는 4byte(32bit)이다. 근데 기종마다 다르다 핸드폰에서는 2바이트
	// 플랫폼마다 int형의 크기가 다름(Window,IOS,안드로이드 등)
	// 언리얼에서는 int형의 크기를 명시해야 한다.
	// 주로 int32를 자주 사용한다. 8이랑 16은 블루프린트 지원이 안된다
	// UPROPERTY로 블루프린트에서 보이게 하려 하면 컴파일오류남
	int8 num8; //8bit
	int16 num16;//16bit
	int32 num32;//32it
	int64 num64;//64bit
private: //외부 접근 불가
	UPROPERTY(EditAnywhere, BlueprintReadWrite,meta = (AllowPrivateAccess = true))
	int32 AccessTest;
	//meta = (AllowPrivateAccess = true) => private변수를 블루프린트에서 접근 허용

};

//코딩표기법
// 혼자 개발할경우 중요하지 않지만 협업시 중요한 요소
// 일관성 있는 규칙으로 팀원에게 빠른 이해가 가능하도록 함
// 코드유지보수가 용이해지
// 
// 1. 카멜표기법
// 단어의 첫글자는 소문자, 이후 단어는 대문자를 사용
// ex)playerPosition, currentHP, distanceToTarget
// 
// 2. 파스칼 표기법
// 모든 단어의 첫글자를 대문자
// ex) CreateEnemy, LookAtEnemy,OnMouseDown
// 
// 3. 헝가리안 표기법
// 변수 및 함수 앞에 데이터 타입 표기
// ex) bAttack(bool형), fDefefnse(float형), m_iCount(멤버변수 int형), m_strName(멤버변수 string형), g_iTest(전역변수 int형)
// 
// 4. 스네이크 표기법
// 단어를 언더바(_)로 구분하며 소문자로 표기
// ex) enemy_position, look_at_target, player_to_move
// 
// 표기법 사용
// 표기법은 엔진에 맞추는것이 가장 좋다.
// 회사 내규 규칙이 있다면 회사 내규를 먼저 우선시
// 프로그램은 1명이 만든것처럼 표기법을 사용해야 함
// bool형은 변수 앞에 b 또는 is를 붙인다.
// ex)bMove, isMove, bAttack, isAttack
// 함수와 변수명은 기능을 할 수 있는 명확한 단어를 사용
// ex)예외적으로 반복문은 i,j,k를 사용
// 계산에 논리적ㅇ로 ()가필요 없어도 ()를 넣어준다.
// ex)result = a + (b * 2)
// 주의가 필요한 함수 또는 이슈는 주석을 달아줄 것
// 
// 언리얼 c++에서 사용할 수 잇는 기능
// *리플렉션(Reflection) : 객체의 정보를 런타임(게임 실행 중)에서 실시간으로 조사
// *가비지컬렉션(Garbage Collection) : 참조되지 않는 개체를 자동 해제
// 직렬화(Serialization) : 객체와 속성정보를 통으로 안전하게 보관하고 로딩
// CDO(Class Default Object) : 객체의 초기값 관리
// 델리게이트(Delegate): 멤버함수의 효율적인 관리
// Editor Integation: 에디터에서 편리하게 값을 보고 편집
// 
