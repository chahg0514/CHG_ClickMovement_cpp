// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "IntroWidget.generated.h"

/**
 * 
 */
UCLASS()
class CPPTEST_API UIntroWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	virtual void NativeOnInitialized() override;
	//���� �ʱ�ȭ�� ����Ǵ� �Լ�
private:
	UPROPERTY(meta = (BindWidget)) //�̰� ���ε��ϰڴٴ� ���ε� �������Ʈ�� ��ư�� ������ ������
		class UButton* StartButton;
	UPROPERTY(meta = (BindWidget))
		class UTextBlock* InfoText;
	//*meta = (BindWidget)
	//UI�� ������Ұ� �������Ʈ�� ������
	//�������Ʈ�� ������ҿ� �̸��� ���ƾ� ��
private:
	UFUNCTION()
		void OnClick();
	
};
