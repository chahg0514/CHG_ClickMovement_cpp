// Fill out your copyright notice in the Description page of Project Settings.


#include "TestActor.h"

// Sets default values
ATestActor::ATestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATestActor::BeginPlay()
{
	Super::BeginPlay();

	//�α� ���
	UE_LOG(LogTemp, Log, TEXT("Log"));
	UE_LOG(LogTemp, Warning, TEXT("Warning"));
	UE_LOG(LogTemp, Error, TEXT("Error"));
	//UE_LOG(ī�װ�,��¼���,TEXT("���ڿ�"))
	//��¼��� ����: Log(���?), Warning(�����),Error(������)

	//���� �α� ���
	int32 a = 10;
	float b = 12.34f;
	FString c = TEXT("Unreal"); //��Ʈ�� �� ���� �� TEXT ��ũ�θ� ����Ѵ�
	UE_LOG(LogTemp, Error, TEXT("a: %d"), a);
	UE_LOG(LogTemp, Error, TEXT("a: %f"), b);
	UE_LOG(LogTemp, Error, TEXT("a: %s"), *c); //��Ʈ���� ����� �� �������͸� �־������

	//��ũ�� �α� ���
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Hello Unreal"));
	//AddOnScreenDebugMessage(ó������ �׳� -1�־��ָ� �ȴٰ� ��, �ð�, ����, TEXT("���ڿ�"));

	//��ũ�� ������ �α� ���
	FString message = FString::Printf(TEXT("a: %d"), a);
	//FString::Printf : %d ���� ���Ÿ���� ���ڿ��� ��ȯ������
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, message);
	
}

// Called every frame
void ATestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

