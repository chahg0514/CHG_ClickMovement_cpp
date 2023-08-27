// Fill out your copyright notice in the Description page of Project Settings.

//���÷��� �ý��� �̿� ����
// Ŭ�����̸�.generated.h ������ include �Ǿ��־�� ��(���� �Ǿ�����)
// Ŭ�������� UCLASS() ��ũ�� ���Ǿ��־�� ��(���� ����)
// Ŭ���� ���� GENERATED_BODY ��ũ�ΰ� ���Ǿ��־�� ��(���� ����)
// ��� ������ UPROPERTY() ��ũ�ΰ� ����ؾ� ��
// ��� �Լ��� UFUCTION() ��ũ�� ����ؾ���
// 
// ������ �÷���
// ���÷��Ǳ���� Ȱ���Ͽ� �𸮾��� ���� ���
// �ڵ带 ���� �������� �Ҵ��ߴ� �޸� ���� �߿��� � ������ ����Ű�� �ʴ� ������ ������ �ִ� ���
// UObject�� ���� �ڽİ�ü�� ���ؼ��� ������ �÷����� ����
// ����� ����ϱ� ���ؼ� UPROPERTY() ��ũ�θ� ����ؾ� �Ѵ�
//


#pragma once //����� �ߺ����� ���� ����

#include "CoreMinimal.h" //�𸮾��� �ּ����� �ٽɱ���� ��Ƶ� �������
#include "GameFramework/Actor.h" //Actor�� ��ӹ����Ƿ� Actor �������
#include "TestActor.generated.h" //���� �������� Blueprintȭ ���ִ� �������

UCLASS() //Ŭ������ �𸮾� ��Ͻ����ִ� ��ũ��(�𸮾� �� Ŭ������ �ִٰ� �˷��ִ� �����̶�� ���� ��)
class CPPTEST_API ATestActor : public AActor
{
	GENERATED_BODY() 
		//�𸮾� Ÿ�� �ý��ۿ� �ʿ��� ����� ���Ե� ��ũ��
		//���� �Լ��� ������ �����ϸ� ��������.
	
public:	
	// Sets default values for this actor's properties
	ATestActor();//������
	//Ŭ���� ��ü�� ������ �� 1ȸ ȣ��
	//�⺻���� �����ϴ� �� ���

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	//���� ���۽�, Ȥ�� ���� �� ���� �� 1ȸ ȣ��

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	//�� �����Ӹ��� ȣ��

	//UPROPERTY
	// ������ �𸮾� ��Ͻ�Ű�� ��ũ��
	// 
	//���λ�(�տ�)
	//Edit : ������ �����ָ� ���� ����
	//Visible: ������ �����ָ� ���� �Ұ���
	//���̻�(�ڿ�)
	//Anywhere:��𿡼���
	//DefaultOnly: �������Ʈ �����Ϳ���
	//InstanceOnly: ������ ��ġ�� ������Ʈ����

	UPROPERTY(EditAnywhere, Category = "Test") //�𸮾� ��Ͻ����ִ� ��ũ��, ��ȣ ���� �ν��Ͻ� ���� ����, ī�װ��� �������Ʈ������ ��� ����
		int32 CurrentHP;
	UPROPERTY(VisibleInstanceOnly, Category = "Test")
		FString MyName;
	//�������Ʈ ����
	//BlueprintReadWrite : �������Ʈ�� �а� ���� ����
	//BlueprintReadOnly: �������Ʈ���� �б⸸ ����
	//�������Ʈ ����� �̰� �θ�Ŭ������ �Ǵ°��� �װ� �ڽ�
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "MyFirstCpp")
		int32 MaxHP;
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "MyFirstCpp")
		float CurrentTime;

	//int��
	// int�� 4byte(32bit)�̴�. �ٵ� �������� �ٸ��� �ڵ��������� 2����Ʈ
	// �÷������� int���� ũ�Ⱑ �ٸ�(Window,IOS,�ȵ���̵� ��)
	// �𸮾󿡼��� int���� ũ�⸦ ����ؾ� �Ѵ�.
	// �ַ� int32�� ���� ����Ѵ�. 8�̶� 16�� �������Ʈ ������ �ȵȴ�
	// UPROPERTY�� �������Ʈ���� ���̰� �Ϸ� �ϸ� �����Ͽ�����
	int8 num8; //8bit
	int16 num16;//16bit
	int32 num32;//32it
	int64 num64;//64bit
private: //�ܺ� ���� �Ұ�
	UPROPERTY(EditAnywhere, BlueprintReadWrite,meta = (AllowPrivateAccess = true))
	int32 AccessTest;
	//meta = (AllowPrivateAccess = true) => private������ �������Ʈ���� ���� ���

};

//�ڵ�ǥ���
// ȥ�� �����Ұ�� �߿����� ������ ������ �߿��� ���
// �ϰ��� �ִ� ��Ģ���� �������� ���� ���ذ� �����ϵ��� ��
// �ڵ����������� ��������
// 
// 1. ī��ǥ���
// �ܾ��� ù���ڴ� �ҹ���, ���� �ܾ�� �빮�ڸ� ���
// ex)playerPosition, currentHP, distanceToTarget
// 
// 2. �Ľ�Į ǥ���
// ��� �ܾ��� ù���ڸ� �빮��
// ex) CreateEnemy, LookAtEnemy,OnMouseDown
// 
// 3. �밡���� ǥ���
// ���� �� �Լ� �տ� ������ Ÿ�� ǥ��
// ex) bAttack(bool��), fDefefnse(float��), m_iCount(������� int��), m_strName(������� string��), g_iTest(�������� int��)
// 
// 4. ������ũ ǥ���
// �ܾ �����(_)�� �����ϸ� �ҹ��ڷ� ǥ��
// ex) enemy_position, look_at_target, player_to_move
// 
// ǥ��� ���
// ǥ����� ������ ���ߴ°��� ���� ����.
// ȸ�� ���� ��Ģ�� �ִٸ� ȸ�� ���Ը� ���� �켱��
// ���α׷��� 1���� �����ó�� ǥ����� ����ؾ� ��
// bool���� ���� �տ� b �Ǵ� is�� ���δ�.
// ex)bMove, isMove, bAttack, isAttack
// �Լ��� �������� ����� �� �� �ִ� ��Ȯ�� �ܾ ���
// ex)���������� �ݺ����� i,j,k�� ���
// ��꿡 �������� ()���ʿ� ��� ()�� �־��ش�.
// ex)result = a + (b * 2)
// ���ǰ� �ʿ��� �Լ� �Ǵ� �̽��� �ּ��� �޾��� ��
// 
// �𸮾� c++���� ����� �� �մ� ���
// *���÷���(Reflection) : ��ü�� ������ ��Ÿ��(���� ���� ��)���� �ǽð����� ����
// *�������÷���(Garbage Collection) : �������� �ʴ� ��ü�� �ڵ� ����
// ����ȭ(Serialization) : ��ü�� �Ӽ������� ������ �����ϰ� �����ϰ� �ε�
// CDO(Class Default Object) : ��ü�� �ʱⰪ ����
// ��������Ʈ(Delegate): ����Լ��� ȿ������ ����
// Editor Integation: �����Ϳ��� ���ϰ� ���� ���� ����
// 
