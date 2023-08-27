// Fill out your copyright notice in the Description page of Project Settings.


#include "ClickMoveCharacter.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

bool isSpawn;
// Sets default values
AClickMoveCharacter::AClickMoveCharacter()
{
	HitEnemyCount = 0;
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
	//����÷��� ȣ�� �� ƽ�Լ� ȣ��

	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.f);
	//ĸ��������Ʈ �ʱ������(Init:�ʱ�) ����

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
	//ĳ���Ͱ� ��Ʈ�ѷ��� ȸ���� ������ ���� ����

	
	//�޽� ����
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> MeshAsset(TEXT("SkeletalMesh'/Game/Mannequin/Character/Mesh/SK_Mannequin.SK_Mannequin'"));
	//TEXT(L"") �̰͵� �Ǵµ�, �̰Թ��ĸ� ���̷�ƮX ���� L�� ����ؼ� ��θ� ã�´�. �𸮾��� ���̷�Ʈx�� �������
	if (MeshAsset.Succeeded())
	{
		//���̷�Ż �޽��� ������� ��ɾ GetMesh���?? 0512 6�� 27�� ����
		GetMesh()->SetSkeletalMesh(MeshAsset.Object);
	}
	GetMesh()->SetRelativeLocation(FVector(0, 0, -90));
	GetMesh()->SetRelativeRotation(FRotator(0, -90, 0));
	GetMesh()->SetAnimationMode(EAnimationMode::AnimationBlueprint);
	//�ִϸ��̼� �������Ʈ�� ���
	//�ִϸ��̼� : Class�� �����´� 0512 6�� 31�� ����

	static ConstructorHelpers::FClassFinder<UAnimInstance> AnimAsset(TEXT("AnimBlueprint'/Game/Mannequin/Animations/ThirdPerson_AnimBP.ThirdPerson_AnimBP_C'"));
	if (AnimAsset.Succeeded())
	{
		GetMesh()->SetAnimInstanceClass(AnimAsset.Class);
	}
	//��������
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent); //���������� ��Ʈ������Ʈ�� �ٿ���, ��Ʈ������Ʈ�� �Ⱥ��̰� ������Ʈ �����ϸ� ���ȵǴ°Ű���
	SpringArm->SetUsingAbsoluteRotation(true);
	//���������� ȸ���� ������ǥ�� ���� ȸ��
	SpringArm->bDoCollisionTest = false;
	//��ֹ��� �־ ī�޶� �� ���� �׳� ������
	SpringArm->TargetArmLength = 800.f;
	SpringArm->SetRelativeRotation(FRotator(-60, 45, 0));


	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);
	Camera->bUsePawnControlRotation = false;
	//�� ȸ���� ������ ���� ����

	//ĳ���� �����Ʈ �̰� ���� �޷��ִ� ������Ʈ����
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0, 640, 0);
	GetCharacterMovement()->bConstrainToPlane = true;
	//ĳ������ �̵��� ������� ����
	GetCharacterMovement()->bSnapToPlaneAtStart = true;
	//ĳ���Ͱ� ����� ��� ��� ��鿡 �ٿ���
	
}

// Called when the game starts or when spawned
void AClickMoveCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AClickMoveCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AClickMoveCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


void AClickMoveCharacter::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	if (Other->ActorHasTag(FName(TEXT("Enemy"))))
	{
		if (!isHit)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, TEXT("ReachEnemy"));
			++HitEnemyCount;
			isHit = true;
			if (HitEnemyCount > 4)
			{
				//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, TEXT("OverFour"));
				this->Destroy();
			}
			GetWorld()->GetTimerManager().SetTimer(SpawnTimerHandle, FTimerDelegate::CreateLambda([&]()
				{
					// ���� ���ϴ� �ڵ� ����
					//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, TEXT("Delay"));
					isHit = false;

					// Ÿ�̸� �ʱ�ȭ
					GetWorld()->GetTimerManager().ClearTimer(SpawnTimerHandle);
				}), 1.f, false);
		}
		
		
		
		
	}
	
}


