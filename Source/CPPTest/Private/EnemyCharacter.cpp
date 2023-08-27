// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "BehaviorTree/BehaviorTree.h" //�̰� �� �ǳ�..
#include "EnemyAIController.h"


// Sets default values
AEnemyCharacter::AEnemyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//AEnemyCharacter::StaticClass()->Tag
	Tags.Add(FName("Enemy"));
	//	Tags.Add(FName(��123��));
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;

	MyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyMesh"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	if (MeshAsset.Succeeded())
	{
		//MyMesh = MeshAsset.Object;
		MyMesh->SetStaticMesh(MeshAsset.Object);
	}
	//�޽�������Ʈ���� ���� ����ƽ�޽ð� ���̷������� �Ǿ��ִ�
	MyMesh->AttachTo(RootComponent);

	//�����̺�� Ʈ�� �������� ���
	static ConstructorHelpers::FObjectFinder<UBehaviorTree> BTAsset(TEXT("BehaviorTree'/Game/Blueprint/BT_Enemy.BT_Enemy'"));
	if (BTAsset.Succeeded())
	{
		EnemyBehaviorTree = BTAsset.Object;
	}
	AIControllerClass = AEnemyAIController::StaticClass();
	GetCharacterMovement()->MaxWalkSpeed = 400.f;
}

// Called when the game starts or when spawned
void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

