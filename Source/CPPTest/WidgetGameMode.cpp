// Fill out your copyright notice in the Description page of Project Settings.


#include "WidgetGameMode.h"

#include "Kismet/GameplayStatics.h"

AWidgetGameMode::AWidgetGameMode()
{
	static ConstructorHelpers::FClassFinder<UUserWidget> WidgetAsset(TEXT("WidgetBlueprint'/Game/Blueprint/BP_IntroWidget.BP_IntroWidget_C'"));
	//블루프린트는 경로에 _C를 붙여야 한다.
	if (IntroWidgetClass != nullptr)
	{
		//Cu
	}
}

