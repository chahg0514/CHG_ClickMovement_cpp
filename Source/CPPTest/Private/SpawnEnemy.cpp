// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnEnemy.h"
#include "EnemyCharacter.h"
#include "Math/UnrealMathUtility.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Actor.h"



SpawnEnemy::SpawnEnemy()
{
	random = 1;
}

SpawnEnemy::~SpawnEnemy()
{

}

//void AActor::BeginPlay()
//{
//	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, TEXT("BeginPlay"));
//	/*UGameplayStatics::GetPlayerCharacter(WorldRef->GetWorld(), 0);
//	player = Cast<AClickMoveCharacter>(UGameplayStatics::GetPlayerCharacter(WorldRef->GetWorld(), 0));
//	WorldRef->GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &SpawnEnemy::KeepSpawn, 5.f, true);*/
//}

void SpawnEnemy::KeepSpawn()
{
	FTransform Transform;
	Transform.SetLocation(player->GetActorLocation() + (player->GetActorForwardVector() * 100.f));
	random = FMath::RandRange(-2, 2);
	if (random != 0)
	{
		Transform.SetLocation(player->GetActorLocation() + (player->GetActorForwardVector() * 100.f * random));
		WorldRef->GetWorld()->SpawnActor<AEnemyCharacter>(AEnemyCharacter::StaticClass(), Transform);
	}
	
}
