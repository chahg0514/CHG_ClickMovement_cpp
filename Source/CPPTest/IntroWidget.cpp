// Fill out your copyright notice in the Description page of Project Settings.


#include "IntroWidget.h"

#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Kismet/GamePlayStatics.h"

void UIntroWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	StartButton->OnClicked.AddDynamic(this, &UIntroWidget::OnClick); 
	//OnCliked : ��ư�� ������ ����Ǵ� ��������Ʈ ����
	//OnCliked�� ���� => ���� �� ��ư�� Ŭ���ϸ� OnClick�Լ��� �����
	InfoText->SetText(FText::FromString(TEXT("MyGame")));

}

void UIntroWidget::OnClick()
{
}
