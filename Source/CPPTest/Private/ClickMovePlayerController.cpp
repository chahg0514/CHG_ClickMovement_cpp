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
	InputComponent->BindAction(TEXT("LeftClick"), IE_Pressed, this, &AClickMovePlayerController::GetMouseButtonDown); //GetMouseButtonDown �Լ��� ȣ��ǵ��� ����
	InputComponent->BindAction(TEXT("LeftClick"), IE_Released, this, &AClickMovePlayerController::GetMouseButtonUp);
	InputComponent->BindAction(TEXT("Shot"), IE_Pressed, this, &AClickMovePlayerController::Shot);
	InputComponent->BindAction(TEXT("Missile"), IE_Pressed, this, &AClickMovePlayerController::MissileAttack);
}
void AClickMovePlayerController::BeginPlay()
{
	Super::BeginPlay();
	FTransform Transform;

	//IsValid: Actor�� ��ȿ���� �˻�(���� ��������� ������ �˻�)
	//GetPawn(): ��Ʈ�ѷ��� �������� ���� ��ȯ
	if (IsValid(GetPawn()))
	{
		Transform.SetLocation(GetPawn()->GetActorLocation() + (GetPawn()->GetActorForwardVector() * 100.f));
		AShotActor* BulletObj = GetWorld()->SpawnActor<AShotActor>(AShotActor::StaticClass(), Transform);
		AMissileActor* MissileObj = GetWorld()->SpawnActor<AMissileActor>(AMissileActor::StaticClass(), Transform);
		//�����ص� ��ġ�� �Ѿ� ����
		BulletObj->SetActive(false); //�Ѿ� ��Ȱ��ȭ
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
	//GetPawn(): ��Ʈ�ѷ��� �������� ���� ��ȯ
	if (MyPawn != nullptr)
	{
		float const Distance = FVector::Dist(Destination, MyPawn->GetActorLocation());
		//FVector::Dist: �� ��ġ�� �Ÿ��� ��ȯ
		//MyPawn->GetActorLocation(): �������� ���� ��ġ��, �Ű����� ������ �Ÿ� ���
		if (Distance > 100.f)
		{
			UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, Destination); //�̰� ������ CPPTest.cpp.cs ���� ���� �� �߰������ ��
			//SimpleMoveToLocation: �׺���̼Ǻ��� ��� Ư����ġ�� �̵�
		}
	}
}
void AClickMovePlayerController::MoveToMouseCursor()
{
	FHitResult HitResult;
	GetHitResultUnderCursor(ECC_Visibility, false, HitResult);
	//GetHitResultUnderCursor: ȭ�鿡 ���콺��ġ�� Ʈ���̽� �߻� �� ����� HitResult�� �־���
	if (HitResult.bBlockingHit) //�浹���� ������� �浹�ߴٸ�
	{
		SetDestination(HitResult.ImpactPoint);
	}
}

void AClickMovePlayerController::Shot()
{
	if (!IsValid(GetPawn())) return; //����� �÷��̾ ���ٸ� �Լ� ����
	for (auto Item : Bullet)
	{
		if (!Item->isActive()) //��Ȱ��ȭ ���¶��
		{
			Item->SetActive(true);
			Item->SetActorRelativeLocation(GetPawn()->GetActorLocation() + (GetPawn()->GetActorForwardVector() * 100.f));
			//�Ѿ��� ��ġ�� �÷��̾��� ������ ����
			Item->FireInDirection(GetPawn()->GetActorForwardVector());
			//�Ѿ��� ���ư��� ������ ���� �չ���
			return;
		}
	}
	//�پ��������� ���� ����°�
	FTransform Transform;
	Transform.SetLocation(GetPawn()->GetActorLocation() + (GetPawn()->GetActorForwardVector() * 100.f));
	AShotActor* BulletObj = GetWorld()->SpawnActor<AShotActor>(AShotActor::StaticClass(), Transform);
	BulletObj->FireInDirection(GetPawn()->GetActorForwardVector());
	BulletObj->SetActive(true);
	Bullet.Add(BulletObj);
}

void AClickMovePlayerController::MissileAttack()
{
	if (!IsValid(GetPawn())) return; //����� �÷��̾ ���ٸ� �Լ� ����
	for (auto Item : Missile)
	{
		if (!Item->isActive()) //��Ȱ��ȭ ���¶��
		{
			Item->SetActive(true);
			Item->SetActorRelativeLocation(GetPawn()->GetActorLocation() + (GetPawn()->GetActorForwardVector() * 100.f));
			//�Ѿ��� ��ġ�� �÷��̾��� ������ ����
			Item->FireInDirection(GetPawn()->GetActorForwardVector());
			//�Ѿ��� ���ư��� ������ ���� �չ���
			return;
		}
	}
	//�پ��������� ���� ����°�
	FTransform Transform;
	Transform.SetLocation(GetPawn()->GetActorLocation() + (GetPawn()->GetActorForwardVector() * 100.f));
	AMissileActor* MissileObj = GetWorld()->SpawnActor<AMissileActor>(AMissileActor::StaticClass(), Transform);
	MissileObj->FireInDirection(GetPawn()->GetActorForwardVector());
	MissileObj->SetActive(true);
	Missile.Add(MissileObj);
}
