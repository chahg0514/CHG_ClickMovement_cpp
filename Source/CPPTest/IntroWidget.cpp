// Fill out your copyright notice in the Description page of Project Settings.


#include "IntroWidget.h"

#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Kismet/GamePlayStatics.h"

void UIntroWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	StartButton->OnClicked.AddDynamic(this, &UIntroWidget::OnClick); 
	//OnCliked : 버튼을 누르면 실행되는 델리게이트 변수
	//OnCliked랑 연결 => 이제 이 버튼을 클릭하면 OnClick함수가 실행됨
	InfoText->SetText(FText::FromString(TEXT("MyGame")));

}

void UIntroWidget::OnClick()
{
}
