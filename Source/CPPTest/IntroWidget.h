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
	//위젯 초기화시 실행되는 함수
private:
	UPROPERTY(meta = (BindWidget)) //이게 바인드하겠다는 뜻인데 블루프린트에 버튼이 없으면 오류남
		class UButton* StartButton;
	UPROPERTY(meta = (BindWidget))
		class UTextBlock* InfoText;
	//*meta = (BindWidget)
	//UI의 구성요소가 블루프린트와 연동됨
	//블루프린트의 구성요소와 이름이 같아야 함
private:
	UFUNCTION()
		void OnClick();
	
};
