// Fill out your copyright notice in the Description page of Project Settings.


#include "WidgetGameMode.h"

#include "Kismet/GameplayStatics.h"

AWidgetGameMode::AWidgetGameMode()
{
	static ConstructorHelpers::FClassFinder<UUserWidget> WidgetAsset(TEXT("WidgetBlueprint'/Game/Blueprint/BP_IntroWidget.BP_IntroWidget_C'"));
	//�������Ʈ�� ��ο� _C�� �ٿ��� �Ѵ�.
	if (IntroWidgetClass != nullptr)
	{
		//Cu
	}
}

