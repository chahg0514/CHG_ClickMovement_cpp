// Fill out your copyright notice in the Description page of Project Settings.


#include "ClickMovePlayerController.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "MissileActor.h"
#include "ShotActor.h"

AClickMovePlayerController::AClickMovePlayerController()
{
	bShowMouseCursor = true;
}

void AClickMovePlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
	if (isClick)
	{
		MoveToMouseCursor();
	}

}
void AClickMovePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	InputComponent->BindAction(TEXT("LeftClick"), IE_Pressed, this, &AClickMovePlayerController::GetMouseButtonDown); //GetMouseButtonDown 함수가 호출되도록 연결
	InputComponent->BindAction(TEXT("LeftClick"), IE_Released, this, &AClickMovePlayerController::GetMouseButtonUp);
	InputComponent->BindAction(TEXT("Shot"), IE_Pressed, this, &AClickMovePlayerController::Shot);
	InputComponent->BindAction(TEXT("Missile"), IE_Pressed, this, &AClickMovePlayerController::MissileAttack);
}
void AClickMovePlayerController::BeginPlay()
{
	Super::BeginPlay();
	FTransform Transform;

	//IsValid: Actor가 유효한지 검사(삭제 대기중인지 까지도 검사)
	//GetPawn(): 컨트롤러가 조종중인 폰을 반환
	if (IsValid(GetPawn()))
	{
		Transform.SetLocation(GetPawn()->GetActorLocation() + (GetPawn()->GetActorForwardVector() * 100.f));
		AShotActor* BulletObj = GetWorld()->SpawnActor<AShotActor>(AShotActor::StaticClass(), Transform);
		AMissileActor* MissileObj = GetWorld()->SpawnActor<AMissileActor>(AMissileActor::StaticClass(), Transform);
		//지정해둔 위치에 총알 생성
		BulletObj->SetActive(false); //총알 비활성화
		MissileObj->SetActive(false);
		Bullet.Add(BulletObj);
		Missile.Add(MissileObj);
	}
	
}
void AClickMovePlayerController::GetMouseButtonDown()
{
	isClick = true;
}
void AClickMovePlayerController::GetMouseButtonUp()
{
	isClick = false;
}
void AClickMovePlayerController::SetDestination(const FVector Destination)
{
	APawn* const MyPawn = GetPawn();
	//GetPawn(): 컨트롤러가 조종중인 폰을 반환
	if (MyPawn != nullptr)
	{
		float const Distance = FVector::Dist(Destination, MyPawn->GetActorLocation());
		//FVector::Dist: 두 위치의 거리를 반환
		//MyPawn->GetActorLocation(): 조종중인 폰의 위치랑, 매개변수 사이의 거리 계산
		if (Distance > 100.f)
		{
			UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, Destination); //이거 쓰려면 CPPTest.cpp.cs 파일 가서 뭐 추가해줘야 함
			//SimpleMoveToLocation: 네비게이션볼륨 기반 특정위치로 이동
		}
	}
}
void AClickMovePlayerController::MoveToMouseCursor()
{
	FHitResult HitResult;
	GetHitResultUnderCursor(ECC_Visibility, false, HitResult);
	//GetHitResultUnderCursor: 화면에 마우스위치로 트레이스 발사 후 결과를 HitResult로 넣어줌
	if (HitResult.bBlockingHit) //충돌상대와 블록으로 충돌했다면
	{
		SetDestination(HitResult.ImpactPoint);
	}
}

void AClickMovePlayerController::Shot()
{
	if (!IsValid(GetPawn())) return; //연결된 플레이어가 없다면 함수 종료
	for (auto Item : Bullet)
	{
		if (!Item->isActive()) //비활성화 상태라면
		{
			Item->SetActive(true);
			Item->SetActorRelativeLocation(GetPawn()->GetActorLocation() + (GetPawn()->GetActorForwardVector() * 100.f));
			//총알의 위치를 플레이어의 앞으로 변경
			Item->FireInDirection(GetPawn()->GetActorForwardVector());
			//총알이 날아가는 방향은 폰의 앞방향
			return;
		}
	}
	//다쓰고있으면 새로 만드는거
	FTransform Transform;
	Transform.SetLocation(GetPawn()->GetActorLocation() + (GetPawn()->GetActorForwardVector() * 100.f));
	AShotActor* BulletObj = GetWorld()->SpawnActor<AShotActor>(AShotActor::StaticClass(), Transform);
	BulletObj->FireInDirection(GetPawn()->GetActorForwardVector());
	BulletObj->SetActive(true);
	Bullet.Add(BulletObj);
}

void AClickMovePlayerController::MissileAttack()
{
	if (!IsValid(GetPawn())) return; //연결된 플레이어가 없다면 함수 종료
	for (auto Item : Missile)
	{
		if (!Item->isActive()) //비활성화 상태라면
		{
			Item->SetActive(true);
			Item->SetActorRelativeLocation(GetPawn()->GetActorLocation() + (GetPawn()->GetActorForwardVector() * 100.f));
			//총알의 위치를 플레이어의 앞으로 변경
			Item->FireInDirection(GetPawn()->GetActorForwardVector());
			//총알이 날아가는 방향은 폰의 앞방향
			return;
		}
	}
	//다쓰고있으면 새로 만드는거
	FTransform Transform;
	Transform.SetLocation(GetPawn()->GetActorLocation() + (GetPawn()->GetActorForwardVector() * 100.f));
	AMissileActor* MissileObj = GetWorld()->SpawnActor<AMissileActor>(AMissileActor::StaticClass(), Transform);
	MissileObj->FireInDirection(GetPawn()->GetActorForwardVector());
	MissileObj->SetActive(true);
	Missile.Add(MissileObj);
}
