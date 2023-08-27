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
	//비긴플레이 호출 후 틱함수 호출

	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.f);
	//캡슐컴포넌트 초기사이즈(Init:초기) 변경

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
	//캐릭터가 컨트롤러의 회전에 영향을 받지 않음

	
	//메쉬 설정
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> MeshAsset(TEXT("SkeletalMesh'/Game/Mannequin/Character/Mesh/SK_Mannequin.SK_Mannequin'"));
	//TEXT(L"") 이것도 되는데, 이게뭐냐면 다이렉트X 에서 L을 사용해서 경로를 찾는다. 언리얼이 다이렉트x로 만들어짐
	if (MeshAsset.Succeeded())
	{
		//스켈레탈 메쉬를 갖고오는 명령어가 GetMesh라고?? 0512 6시 27분 이후
		GetMesh()->SetSkeletalMesh(MeshAsset.Object);
	}
	GetMesh()->SetRelativeLocation(FVector(0, 0, -90));
	GetMesh()->SetRelativeRotation(FRotator(0, -90, 0));
	GetMesh()->SetAnimationMode(EAnimationMode::AnimationBlueprint);
	//애니메이션 블루프린트를 사용
	//애니메이션 : Class로 가져온다 0512 6시 31분 이후

	static ConstructorHelpers::FClassFinder<UAnimInstance> AnimAsset(TEXT("AnimBlueprint'/Game/Mannequin/Animations/ThirdPerson_AnimBP.ThirdPerson_AnimBP_C'"));
	if (AnimAsset.Succeeded())
	{
		GetMesh()->SetAnimInstanceClass(AnimAsset.Class);
	}
	//스프링암
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent); //스프링암을 루트컴포넌트에 붙여줌, 루트컴포넌트에 안붙이고 컴포넌트 선언만하면 사용안되는거겠지
	SpringArm->SetUsingAbsoluteRotation(true);
	//스프링암의 회전이 월드좌표에 따라 회전
	SpringArm->bDoCollisionTest = false;
	//장애물이 있어도 카메라가 그 속을 그냥 비춰줌
	SpringArm->TargetArmLength = 800.f;
	SpringArm->SetRelativeRotation(FRotator(-60, 45, 0));


	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);
	Camera->bUsePawnControlRotation = false;
	//폰 회전에 영향을 받지 않음

	//캐릭터 무브먼트 이건 원래 달려있는 컴포넌트겠지
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0, 640, 0);
	GetCharacterMovement()->bConstrainToPlane = true;
	//캐릭터의 이동을 평면으로 제한
	GetCharacterMovement()->bSnapToPlaneAtStart = true;
	//캐릭터가 평면을 벗어난 경우 평면에 붙여줌
	
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
					// 내가 원하는 코드 구현
					//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, TEXT("Delay"));
					isHit = false;

					// 타이머 초기화
					GetWorld()->GetTimerManager().ClearTimer(SpawnTimerHandle);
				}), 1.f, false);
		}
		
		
		
		
	}
	
}


