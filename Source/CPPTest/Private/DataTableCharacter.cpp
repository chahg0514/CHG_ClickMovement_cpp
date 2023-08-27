// Fill out your copyright notice in the Description page of Project Settings.


#include "DataTableCharacter.h"
#include "DataGameInstance.h"
#include "DataTableStruct.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ADataTableCharacter::ADataTableCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADataTableCharacter::BeginPlay()
{
	Super::BeginPlay();
	SetCharacterInfo(5);

	FString message = FString::Printf(TEXT("%d / %d / %d / %f"), InfoDataTable->Level, InfoDataTable->NextExp, InfoDataTable->TotalExp, InfoDataTable->Atk);
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, FString::Printf(TEXT("%d / %d / %d / %f"), InfoDataTable->Level, InfoDataTable->NextExp, InfoDataTable->TotalExp, InfoDataTable->Atk));
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, message);
	
}

// Called every frame
void ADataTableCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ADataTableCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ADataTableCharacter::SetCharacterInfo(int32 Level)
{
	UDataGameInstance* Instance = Cast<UDataGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	//게임 인스턴스를 가져옴

	//!! : != nullptr과 같은 뜻 그니까 비어있지 않냐 이거인듯
	//if(Instance != nullptr)
	//if(Instance) 다됨
	if (!!Instance)
	{
		InfoDataTable = Instance->GetDataTable(Level); //게임인스턴스에 쓴 함수
		//인스턴스의 데이터를 가져옴
		if (InfoDataTable == nullptr)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("DataTable Load Faild"));
		}
	}
}

